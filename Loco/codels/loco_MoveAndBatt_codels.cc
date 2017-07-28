#include "serial.hpp"

#include "acloco.h"

#include "loco_c_types.h"


/* Some macros to make my life easier. */
#define check_port_in_p(port) (((port)->read(self) == genom_ok) && ((port)->data(self)))
#define check_port_in(port,exception) if (((port)->read(self) != genom_ok) || !((port)->data(self))) return (exception)(self)
#define check_port_out(port,exception) if ((port)->data(self) == NULL) return (exception)(self)

#define bind_port_out(port,exception) if (((port ## Data) = (port)->data(self)) == NULL) return (exception)(self)
#define bind_port_in(port,exception) if (((port)->read(self) != genom_ok)  || !((port)->data(self))) return (exception)(self); else (port ## Data) = (port)->data(self)
#define write_port(port,exception) if ((port)->write(self) != genom_ok) return (exception)(self)



/* --- Task MoveAndBatt ------------------------------------------------- */


/** Codel InitMoveAndBattParameters of task MoveAndBatt.
 *
 * Triggered by loco_start.
 * Yields to loco_ether.
 */
genom_event
InitMoveAndBattParameters(loco_data *batterie, loco_motor *moteur,
                          const genom_context self)
{
  batterie->nombre = 0;		// instanciation du niveau de batterie à 0%

  moteur->moteur_gauche.direction = loco_STOP;		// instanciation avec l'arrêt des moteurs
  moteur->moteur_droit.direction = loco_STOP;		// gauche et droit : le robot est arrêté

  return loco_ether;
}


/* --- Activity StartMove ----------------------------------------------- */

/** Codel MoveStart of activity StartMove.
 *
 * Triggered by loco_start.
 * Yields to loco_moteur, loco_ether.
 * Throws loco_INVALID_ORDER.
 */
genom_event
MoveStart(const loco_JS *JS, const loco_AR *AR, const loco_POS *POS,
          const genom_context self)
{
  display_order *JSData;
  bind_port_in(JS,loco_INVALID_DATA);
  camera_arena *ARData;
  bind_port_in(AR,loco_INVALID_DATA);
  camera_robot *POSData;
  bind_port_in(POS,loco_INVALID_DATA);

  if ((JSData->order == display_UP) && ((POSData->position_avant.x <= ARData->haut_gauche.x + 5)
				    ||  (POSData->position_avant.y <= ARData->bas_gauche.y + 5)
				    ||  (POSData->position_avant.x >= ARData->haut_droit.x - 5)
				    ||  (POSData->position_avant.y >= ARData->haut_gauche.y - 5)))
  {
    return loco_INVALID_ORDER(self);
  }
  else if ((JSData->order == display_DOWN) &&
		    ((POSData->position_arriere_droit.x <= ARData->haut_gauche.x + 5)
		||  (POSData->position_arriere_gauche.x <= ARData->haut_gauche.x + 5)
		||  (POSData->position_arriere_droit.y <= ARData->bas_gauche.y + 5)
		||  (POSData->position_arriere_gauche.y <= ARData->bas_gauche.y + 5)
		||  (POSData->position_arriere_droit.x >= ARData->haut_droit.x - 5)
		||  (POSData->position_arriere_gauche.x >= ARData->haut_droit.x - 5)
		||  (POSData->position_arriere_droit.y >= ARData->haut_gauche.y - 5)
		||  (POSData->position_arriere_gauche.y >= ARData->haut_gauche.y - 5)))
  {
    return loco_INVALID_ORDER(self);
  }

  return loco_moteur;
}

/** Codel MoveMot of activity StartMove.
 *
 * Triggered by loco_moteur.
 * Yields to loco_compute_speed.
 * Throws loco_INVALID_ORDER.
 */
genom_event
MoveMot(const loco_JS *JS, loco_motor *moteur,
        const genom_context self)
{
  display_order *JSData;
  bind_port_in(JS,loco_INVALID_DATA);

  if (JSData->order == display_UP)
  {
    moteur->moteur_gauche.direction = loco_AVANT;
    moteur->moteur_droit.direction = loco_AVANT;
  }
  else if (JSData->order == display_DOWN)
  {
    moteur->moteur_gauche.direction = loco_ARRIERE;
    moteur->moteur_droit.direction = loco_ARRIERE;
  }
  else if (JSData->order == display_LEFT)
  {
    moteur->moteur_gauche.direction = loco_ARRIERE;		// rotation sans déplacement
    moteur->moteur_droit.direction = loco_AVANT;
  }
  else if (JSData->order == display_RIGHT)
  {
    moteur->moteur_gauche.direction = loco_AVANT;		// rotation sans déplacement
    moteur->moteur_droit.direction = loco_ARRIERE;
  }
  else if (JSData->order == display_STOP)
  {
    moteur->moteur_gauche.direction = loco_STOP;
    moteur->moteur_droit.direction = loco_STOP;
  }

  return loco_compute_speed;
}

/** Codel MoveSpeed of activity StartMove.
 *
 * Triggered by loco_compute_speed.
 * Yields to loco_ether.
 * Throws loco_INVALID_ORDER.
 */
genom_event
MoveSpeed(int32_t fd, const loco_motor *moteur,
          const genom_context self)
{

  /* Envoie de la commande aux moteurs du robot */

  switch (moteur->moteur_gauche.direction)
  {
    case loco_AVANT:
    switch (moteur->moteur_droit.direction)
    {
      case loco_AVANT:
	robotCmd(fd,GOFORWARD,NULL);
        break;
      case loco_ARRIERE:
      robotCmd(fd,TURNRIGHT,NULL);
        break;
    }
      break;
    case loco_ARRIERE:
    switch (moteur->moteur_droit.direction)
    {
      case loco_AVANT:
      robotCmd(fd,TURNLEFT,NULL);
        break;
      case loco_ARRIERE:
      robotCmd(fd,GOBACK,NULL);
        break;
    }
      break;
    case loco_STOP:
    robotCmd(fd,STOPMOVE,NULL);
      break;
  }  

  return loco_ether;
}


/* --- Activity StartBatt ----------------------------------------------- */

/** Codel BatteryStart of activity StartBatt.
 *
 * Triggered by loco_start.
 * Yields to loco_ether.
 * Throws loco_INVALID_DATA.
 */
genom_event
BatteryStart(int32_t fd, const loco_data *batterie,
             const loco_BAT *BAT, const genom_context self)
{
  /* Récupération du niveau de batterie du robot */




  /* Ecriture du niveau de batterie dans le port BAT */
  check_port_out(BAT,loco_INVALID_DATA);	// vérification que le port est disponible
  
  BAT->data(self)->nombre = batterie->nombre;
  BAT->write(self);

  return loco_ether;
}
