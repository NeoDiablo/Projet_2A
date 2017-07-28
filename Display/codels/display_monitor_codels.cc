#include "acdisplay.h"

#include "display_c_types.h"


/* Some macros to make my life easier. */
#define check_port_in_p(port) (((port)->read(self) == genom_ok) && ((port)->data(self)))
#define check_port_in(port,exception) if (((port)->read(self) != genom_ok) || !((port)->data(self))) return (exception)(self)
#define check_port_out(port,exception) if ((port)->data(self) == NULL) return (exception)(self)

#define bind_port_out(port,exception) if (((port ## Data) = (port)->data(self)) == NULL) return (exception)(self)
#define bind_port_in(port,exception) if (((port)->read(self) != genom_ok)  || !((port)->data(self))) return (exception)(self); else (port ## Data) = (port)->data(self)
#define write_port(port,exception) if ((port)->write(self) != genom_ok) return (exception)(self)


/* --- Task monitor ----------------------------------------------------- */


/** Codel InitMonitorParameters of task monitor.
 *
 * Triggered by display_start.
 * Yields to display_ether.
 */
genom_event
InitMonitorParameters(camera_map *image, camera_arena *arene,
                      camera_robot *position, loco_data *batterie,
                      const genom_context self)
{
  image->R = 0;		// code RGB de l'image
  image->G = 0;		// instanciation avec une image noire
  image->B = 0;

  arene->haut_gauche.x = 0;		// code de repérage de l'arene
  arene->haut_gauche.y = 50;		// instanciation avec un rectangle de hauteur 50
  arene->haut_droit.x = 100;		// et de longueur 100 à partir du point (0,0)
  arene->haut_droit.y = 50;
  arene->bas_gauche.x = 0;
  arene->bas_gauche.y = 0;
  arene->bas_droit.x = 100;
  arene->bas_droit.y = 0;

  position->position_avant.x = 50;		// code de repérage du robot
  position->position_avant.y = 27;		// instanciation au milieu de l'arene
  position->position_arriere_gauche.x = 47;
  position->position_arriere_gauche.y = 23;
  position->position_arriere_droit.x = 53;
  position->position_arriere_droit.y = 23;

  batterie = 0;		// code de niveau de batterie // instanciation à 0%

  return display_ether;
}


/* --- Activity Monitoring ---------------------------------------------- */

/** Codel StartMonitoring of activity Monitoring.
 *
 * Triggered by display_start.
 * Yields to display_show.
 * Throws display_INVALID_DATA.
 */
genom_event
StartMonitoring(const display_IM *IM, const display_AR *AR,
                const display_POS *POS, const display_BAT *BAT,
                camera_map *image, camera_arena *arene,
                camera_robot *position, loco_data *batterie,
                const genom_context self)
{
  check_port_in(IM,display_INVALID_DATA);	// vérification que chaque port n'est pas vide
  check_port_in(AR,display_INVALID_DATA);	// ou n'a pas un contenu erroné
  check_port_in(POS,display_INVALID_DATA);
  check_port_in(BAT,display_INVALID_DATA);

  image->R = IM->data(self)->R;		// code RGB de l'image
  image->G = IM->data(self)->G;		// code RGB de l'image reçu via le port IM
  image->B = IM->data(self)->B;

  arene->haut_gauche.x = AR->data(self)->haut_gauche.x;	// code de repérage de l'arene
  arene->haut_gauche.y = AR->data(self)->haut_gauche.y;		// données envoyées par AR
  arene->haut_droit.x = AR->data(self)->haut_droit.x;
  arene->haut_droit.y = AR->data(self)->haut_droit.y;
  arene->bas_gauche.x = AR->data(self)->bas_gauche.x;
  arene->bas_gauche.y = AR->data(self)->bas_gauche.y;
  arene->bas_droit.x = AR->data(self)->bas_droit.x;
  arene->bas_droit.y = AR->data(self)->bas_droit.y;

  position->position_avant.x = POS->data(self)->position_avant.x;	// repérage du robot
  position->position_avant.y = POS->data(self)->position_avant.y;	// position envoyée POS
  position->position_arriere_gauche.x = POS->data(self)->position_arriere_gauche.x;
  position->position_arriere_gauche.y = POS->data(self)->position_arriere_gauche.y;
  position->position_arriere_droit.x = POS->data(self)->position_arriere_droit.x;
  position->position_arriere_droit.y = POS->data(self)->position_arriere_droit.y;

  batterie->nombre = BAT->data(self)->nombre;	// niveau de batterie envoyé par BAT

  return display_show;
}

/** Codel ShowMonitoring of activity Monitoring.
 *
 * Triggered by display_show.
 * Yields to display_ether.
 * Throws display_INVALID_DATA.
 */
genom_event
ShowMonitoring(const camera_map *image, const camera_arena *arene,
               const camera_robot *position, const loco_data *batterie,
               const genom_context self)
{
  /* skeleton sample: insert your code */
  /* skeleton sample */ return display_ether;
}
