#include "../../Destijl/src/serial.h"

#include "acloco.h"

#include "loco_c_types.h"


/* Some macros to make my life easier. */
#define check_port_in_p(port) (((port)->read(self) == genom_ok) && ((port)->data(self)))
#define check_port_in(port,exception) if (((port)->read(self) != genom_ok) || !((port)->data(self))) return (exception)(self)
#define check_port_out(port,exception) if ((port)->data(self) == NULL) return (exception)(self)

#define bind_port_out(port,exception) if (((port ## Data) = (port)->data(self)) == NULL) return (exception)(self)
#define bind_port_in(port,exception) if (((port)->read(self) != genom_ok)  || !((port)->data(self))) return (exception)(self); else (port ## Data) = (port)->data(self)
#define write_port(port,exception) if ((port)->write(self) != genom_ok) return (exception)(self)



/* --- Task move -------------------------------------------------------- */


/** Codel InitMoveParameters of task move.
 *
 * Triggered by loco_start.
 * Yields to loco_ether.
 */
genom_event
InitMoveParameters(loco_motor *moteur, const genom_context self)
{
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
    return loco_INVALID_ORDER;
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
    return loco_INVALID_ORDER;
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
MoveSpeed(const loco_motor *moteur, const genom_context self)
{
  /* Ouverture de la communication avec le robot */

  robotOpenCom();

  /* Envoie de la commande aux moteurs du robot */

  switch (moteur->moteur_gauche.direction
  {
    case loco_AVANT:
    switch (moteur->moteur_droit.direction)
    {
      case loco_AVANT:
      robotCmd(GOFORWARD);
        break;
      case loco_ARRIERE:
      robotCmd(TURNRIGHT);
        break;
    }
      break;
    case loco_ARRIERE:
    switch (moteur->moteur_droit.position)
    {
      case loco_AVANT:
      robotCmd(TURNLEFT);
        break;
      case loco_ARRIERE:
      robotCmd(GOBACK);
        break;
    }
      break;
    case loco_STOP:
    robotCmd(STOPMOVE);
      break;
  }  

  return loco_ether;
}
