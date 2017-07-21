#include "serial.hpp"

#include "acloco.h"

#include "loco_c_types.h"


/* --- Function OpenDevice ---------------------------------------------- */

/** Codel OpenDevice of function OpenDevice.
 *
 * Returns genom_ok.
 */
genom_event
OpenDevice(const char *device, int32_t *fd, const genom_context self)
{
  *fd= robotOpenCom(device);

 return genom_ok;
}


/* --- Function CloseDevice --------------------------------------------- */

/** Codel CloseDevice of function CloseDevice.
 *
 * Returns genom_ok.
 */
genom_event
CloseDevice(int32_t *fd, const genom_context self)
{

  robotCloseCom(*fd);

  return genom_ok;
}
