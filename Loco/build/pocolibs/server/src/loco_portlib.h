/* --- Generated by genom 2.99.29. Do not edit -------------------------- */

#ifndef H_LOCO_PORTLIB
#define H_LOCO_PORTLIB

#include <stddef.h>

#include "h2devLib.h"
#include "posterLib.h"

#include "loco_c_types.h"
#include "typecopy.h"

/* forward declaration */
struct genom_component_data;
struct genom_activities;


/* --- builtin ports ------------------------------------------------------- */

/* state */
int	genom_state_loco_init(struct genom_component_data *self);
int	genom_state_loco_update(struct genom_component_data *self,
		struct genom_activities *activities, int tnum);
genom_event
	genom_state_loco_refresh(struct genom_component_data *self);

/* metadata */
int		genom_metadata_loco_init(
			struct genom_component_data *self);
genom_event	genom_metadata_loco_fetch(
			struct genom_component_data *self,
                        const char *comp, pocolibs_metadata_component *meta);


/* === Port methods ======================================================== */


genom_state_component *
		genom_loco_genom_state_data(genom_context self);
genom_event	genom_loco_genom_state_open(genom_context self);
genom_event	genom_loco_genom_state_close(genom_context self);
void		genom_loco_genom_state_delete(genom_context self);

genom_event	genom_loco_genom_state_write(genom_context self);


pocolibs_metadata_component *
		genom_loco_genom_metadata_data(genom_context self);
genom_event	genom_loco_genom_metadata_open(genom_context self);
genom_event	genom_loco_genom_metadata_close(genom_context self);
void		genom_loco_genom_metadata_delete(genom_context self);

genom_event	genom_loco_genom_metadata_write(genom_context self);


display_order *
		genom_loco_JS_data(genom_context self);
genom_event	genom_loco_JS_open(genom_context self);
genom_event	genom_loco_JS_close(genom_context self);
void		genom_loco_JS_delete(genom_context self);

genom_event	genom_loco_JS_connect(
                  const char *name, genom_context self);
genom_event	genom_loco_JS_read(genom_context self);


camera_arena *
		genom_loco_AR_data(genom_context self);
genom_event	genom_loco_AR_open(genom_context self);
genom_event	genom_loco_AR_close(genom_context self);
void		genom_loco_AR_delete(genom_context self);

genom_event	genom_loco_AR_connect(
                  const char *name, genom_context self);
genom_event	genom_loco_AR_read(genom_context self);


camera_robot *
		genom_loco_POS_data(genom_context self);
genom_event	genom_loco_POS_open(genom_context self);
genom_event	genom_loco_POS_close(genom_context self);
void		genom_loco_POS_delete(genom_context self);

genom_event	genom_loco_POS_connect(
                  const char *name, genom_context self);
genom_event	genom_loco_POS_read(genom_context self);


loco_data *
		genom_loco_BAT_data(genom_context self);
genom_event	genom_loco_BAT_open(genom_context self);
genom_event	genom_loco_BAT_close(genom_context self);
void		genom_loco_BAT_delete(genom_context self);

genom_event	genom_loco_BAT_write(genom_context self);



/* === Port structures ===================================================== */


/* --- genom_state ------------------------------------------------------ */

struct genom_loco_genom_state_port {
  loco_genom_state handle;

  struct genom_loco_genom_state_ph {
    POSTER_ID id;
    size_t size;
    genom_state_component buffer;
  }  h;
};

/* initializer */
static __inline__ void
genom_tinit_loco_genom_state_port(
  struct genom_loco_genom_state_port *p)
{
  p->handle.data = genom_loco_genom_state_data;
  p->handle.write = genom_loco_genom_state_write;
  p->h.id = NULL;
  p->h.size = 0;
  genom_tinit_t_genom_state_component(
    &(p->h.buffer));
}

/* finalizer */
static __inline__ void
genom_tfini_loco_genom_state_port(
  struct genom_loco_genom_state_port *p)
{
  genom_tfini_t_genom_state_component(
    &(p->h.buffer));
}


/* --- genom_metadata --------------------------------------------------- */

struct genom_loco_genom_metadata_port {
  loco_genom_metadata handle;

  struct genom_loco_genom_metadata_ph {
    POSTER_ID id;
    size_t size;
    pocolibs_metadata_component buffer;
  }  h;
};

/* initializer */
static __inline__ void
genom_tinit_loco_genom_metadata_port(
  struct genom_loco_genom_metadata_port *p)
{
  p->handle.data = genom_loco_genom_metadata_data;
  p->handle.write = genom_loco_genom_metadata_write;
  p->h.id = NULL;
  p->h.size = 0;
  genom_tinit_t_pocolibs_metadata_component(
    &(p->h.buffer));
}

/* finalizer */
static __inline__ void
genom_tfini_loco_genom_metadata_port(
  struct genom_loco_genom_metadata_port *p)
{
  genom_tfini_t_pocolibs_metadata_component(
    &(p->h.buffer));
}


/* --- JS --------------------------------------------------------------- */

struct genom_loco_JS_port {
  loco_JS handle;

  struct genom_loco_JS_ph {
    POSTER_ID id;
    display_order buffer;
  }  h;
};

/* initializer */
static __inline__ void
genom_tinit_loco_JS_port(
  struct genom_loco_JS_port *p)
{
  p->handle.data = genom_loco_JS_data;
  p->handle.read = genom_loco_JS_read;
  p->h.id = NULL;
  genom_tinit_t_display_order(
    &(p->h.buffer));
}

/* finalizer */
static __inline__ void
genom_tfini_loco_JS_port(
  struct genom_loco_JS_port *p)
{
  genom_tfini_t_display_order(
    &(p->h.buffer));
}


/* --- AR --------------------------------------------------------------- */

struct genom_loco_AR_port {
  loco_AR handle;

  struct genom_loco_AR_ph {
    POSTER_ID id;
    camera_arena buffer;
  }  h;
};

/* initializer */
static __inline__ void
genom_tinit_loco_AR_port(
  struct genom_loco_AR_port *p)
{
  p->handle.data = genom_loco_AR_data;
  p->handle.read = genom_loco_AR_read;
  p->h.id = NULL;
  genom_tinit_t_camera_arena(
    &(p->h.buffer));
}

/* finalizer */
static __inline__ void
genom_tfini_loco_AR_port(
  struct genom_loco_AR_port *p)
{
  genom_tfini_t_camera_arena(
    &(p->h.buffer));
}


/* --- POS -------------------------------------------------------------- */

struct genom_loco_POS_port {
  loco_POS handle;

  struct genom_loco_POS_ph {
    POSTER_ID id;
    camera_robot buffer;
  }  h;
};

/* initializer */
static __inline__ void
genom_tinit_loco_POS_port(
  struct genom_loco_POS_port *p)
{
  p->handle.data = genom_loco_POS_data;
  p->handle.read = genom_loco_POS_read;
  p->h.id = NULL;
  genom_tinit_t_camera_robot(
    &(p->h.buffer));
}

/* finalizer */
static __inline__ void
genom_tfini_loco_POS_port(
  struct genom_loco_POS_port *p)
{
  genom_tfini_t_camera_robot(
    &(p->h.buffer));
}


/* --- BAT -------------------------------------------------------------- */

struct genom_loco_BAT_port {
  loco_BAT handle;

  struct genom_loco_BAT_ph {
    POSTER_ID id;
    size_t size;
    loco_data buffer;
  }  h;
};

/* initializer */
static __inline__ void
genom_tinit_loco_BAT_port(
  struct genom_loco_BAT_port *p)
{
  p->handle.data = genom_loco_BAT_data;
  p->handle.write = genom_loco_BAT_write;
  p->h.id = NULL;
  p->h.size = 0;
  genom_tinit_t_loco_data(
    &(p->h.buffer));
}

/* finalizer */
static __inline__ void
genom_tfini_loco_BAT_port(
  struct genom_loco_BAT_port *p)
{
  genom_tfini_t_loco_data(
    &(p->h.buffer));
}


#endif /* H_LOCO_PORTLIB */
