/* --- Generated by genom 2.99.29. Do not edit -------------------------- */

#include "autoconf/acheader.h"

#include <stdlib.h>
#include <string.h>

#include "loco_control_task.h"

genom_event
genom_pocolibs_raise(genom_event ex, void *detail, size_t size,
                     genom_context self)
{
  struct genom_context_data *data = self->data;

  if (data->exsize < size) {
    void *exdetail = realloc(data->exdetail, size);
    if (!exdetail) return genom_fatal;

    data->exsize = size;
    data->exdetail = exdetail;
  }
  data->ex = ex;
  memcpy(data->exdetail, detail, size);
  return ex;
}

const void *
genom_pocolibs_raised(genom_event *ex, genom_context self)
{
  struct genom_context_data *data = self->data;

  if (ex) *ex = data->ex;
  return data->exdetail;
}
