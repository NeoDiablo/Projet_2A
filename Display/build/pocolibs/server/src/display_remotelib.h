/* --- Generated by genom 2.99.29. Do not edit -------------------------- */

#ifndef H_DISPLAY_REMOTELIB
#define H_DISPLAY_REMOTELIB

#include <stdint.h>

#include "csLib.h"

#include "display_c_types.h"
#include "serialize.h"
#include "typecopy.h"


/* === Remote structures =================================================== */

struct genom_remote {
  pocolibs_metadata_component meta;
  CLIENT_ID csid;
  int id;
};


#endif /* H_DISPLAY_REMOTELIB */
