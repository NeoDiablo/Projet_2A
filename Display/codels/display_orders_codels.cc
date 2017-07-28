#include <stdio.h>

#include "acdisplay.h"

#include "display_c_types.h"


/* Some macros to make my life easier. */
#define check_port_in_p(port) (((port)->read(self) == genom_ok) && ((port)->data(self)))
#define check_port_in(port,exception) if (((port)->read(self) != genom_ok) || !((port)->data(self))) return (exception)(self)
#define check_port_out(port,exception) if ((port)->data(self) == NULL) return (exception)(self)

#define bind_port_out(port,exception) if (((port ## Data) = (port)->data(self)) == NULL) return (exception)(self)
#define bind_port_in(port,exception) if (((port)->read(self) != genom_ok)  || !((port)->data(self))) return (exception)(self); else (port ## Data) = (port)->data(self)
#define write_port(port,exception) if ((port)->write(self) != genom_ok) return (exception)(self)


/* --- Task orders ------------------------------------------------------ */


/** Codel InitOrdersParameters of task orders.
 *
 * Triggered by display_start.
 * Yields to display_ether.
 */
genom_event
InitOrdersParameters(display_order *command, const genom_context self)
{
  command->order = display_STOP;	// On intialise avec la commande d'arrêt

  return display_ether;
}


/* --- Activity SendOrders ---------------------------------------------- */

/** Codel GetChar of activity SendOrders.
 *
 * Triggered by display_start.
 * Yields to display_trad.
 * Throws display_INVALID_ORDER.
 */
genom_event
GetChar(const display_order *command, int32_t *key,
        const genom_context self)
{
  /* Récupération de l'ordre envoyé au clavier */

  *key = getchar();
  
  return display_trad;
}

/** Codel TradAndSendOrder of activity SendOrders.
 *
 * Triggered by display_trad.
 * Yields to display_start, display_ether.
 * Throws display_INVALID_ORDER.
 */
genom_event
TradAndSendOrder(int32_t key, display_order *command,
                 const display_JS *JS, const genom_context self)
{
  /* Traduction de l'ordre reçu */
  /* Pavé zqsd */

  switch (key)
  {
    case 122: /* touche z */
    command->order = display_UP;
      break;
    case 113: /* touche q */
    command->order = display_LEFT;
      break;
    case 115: /* touche s */
    command->order = display_DOWN;
      break;
    case 100: /* touche d */
    command->order = display_RIGHT;
      break;
    case 0: /* on n'appuie pas */
    command->order = display_STOP;
      break;
  }

  /* Ecriture de l'ordre dans le Port JS */

  check_port_out(JS,display_INVALID_DATA);	// vérification que le port est disponible
  
  JS->data(self)->order = command->order;
  JS->write(self);

  return display_start;
}
