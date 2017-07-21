#include "acloco.h"

#include "loco_c_types.h"


/* Some macros to make my life easier. */
#define check_port_in_p(port) (((port)->read(self) == genom_ok) && ((port)->data(self)))
#define check_port_in(port,exception) if (((port)->read(self) != genom_ok) || !((port)->data(self))) return (exception)(self)
#define check_port_out(port,exception) if ((port)->data(self) == NULL) return (exception)(self)

#define bind_port_out(port,exception) if (((port ## Data) = (port)->data(self)) == NULL) return (exception)(self)
#define bind_port_in(port,exception) if (((port)->read(self) != genom_ok)  || !((port)->data(self))) return (exception)(self); else (port ## Data) = (port)->data(self)
#define write_port(port,exception) if ((port)->write(self) != genom_ok) return (exception)(self)



/* --- Task batt -------------------------------------------------------- */


/** Codel InitBattParameters of task batt.
 *
 * Triggered by loco_start.
 * Yields to loco_ether.
 */
genom_event
InitBattParameters(loco_data *batterie, const genom_context self)
{
  batterie->nombre = 0;		// instanciation du niveau de batterie à 0%
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
BatteryStart(const loco_data *batterie, const loco_BAT *BAT,
             const genom_context self)
{
  /* Récupération du niveau de batterie du robot */




  /* Ecriture du niveau de batterie dans le port BAT */
  check_port_out(BAT,loco_INVALID_DATA);	// vérification que le port est disponible
  
  BAT->data(self)->nombre = batterie->nombre;
  BAT->write(self);

  return loco_ether;
}
