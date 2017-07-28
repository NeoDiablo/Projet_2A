#include "accamera.h"

#include "camera_c_types.h"


/* Some macros to make my life easier. */
#define check_port_in_p(port) (((port)->read(self) == genom_ok) && ((port)->data(self)))
#define check_port_in(port,exception) if (((port)->read(self) != genom_ok) || !((port)->data(self))) return (exception)(self)
#define check_port_out(port,exception) if ((port)->data(self) == NULL) return (exception)(self)

#define bind_port_out(port,exception) if (((port ## Data) = (port)->data(self)) == NULL) return (exception)(self)
#define bind_port_in(port,exception) if (((port)->read(self) != genom_ok)  || !((port)->data(self))) return (exception)(self); else (port ## Data) = (port)->data(self)
#define write_port(port,exception) if ((port)->write(self) != genom_ok) return (exception)(self)


/* --- Task film -------------------------------------------------------- */


/** Codel InitMoveParameters of task film.
 *
 * Triggered by camera_start.
 * Yields to camera_ether.
 */
genom_event
InitMoveParameters(camera_map *image, camera_arena *arene,
                   camera_robot *position, const genom_context self)
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

  return camera_ether;
}


/* --- Activity StartFilm ----------------------------------------------- */

/** Codel FilmStart of activity StartFilm.
 *
 * Triggered by camera_start.
 * Yields to camera_calcul_pos.
 * Throws camera_INVALID_DATA.
 */
genom_event
FilmStart(const camera_map *image, const camera_IM *IM,
          const genom_context self)
{
  /* Récupération de l'image prise par la camera */





  /* Ecriture de l'image dans le port IM */
  check_port_out(IM,camera_INVALID_DATA);	// vérification que le port est disponible
  
  IM->data(self)->R = image->R;
  IM->data(self)->G = image->G;
  IM->data(self)->B = image->B;
  IM->write(self);

  return camera_calcul_pos;
}

/** Codel FilmPosition of activity StartFilm.
 *
 * Triggered by camera_calcul_pos.
 * Yields to camera_write.
 * Throws camera_INVALID_DATA.
 */
genom_event
FilmPosition(const camera_map *image, camera_robot *position,
             camera_arena *arene, const genom_context self)
{
  /* skeleton sample: insert your code */
  /* skeleton sample */ return camera_write;
}

/** Codel FilmWrite of activity StartFilm.
 *
 * Triggered by camera_write.
 * Yields to camera_ether.
 * Throws camera_INVALID_DATA.
 */
genom_event
FilmWrite(const camera_robot *position, const camera_arena *arene,
          const camera_AR *AR, const camera_POS *POS,
          const genom_context self)
{
  /* skeleton sample: insert your code */
  /* skeleton sample */ return camera_ether;
}
