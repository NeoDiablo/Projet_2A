/* --- Generated by genom 2.99.29. Do not edit -------------------------- */

#include "autoconf/acheader.h"

#include "commonStructLib.h"

#include "loco_control_task.h"



/* --- task batt -------------------------------------------------------- */

/* state start */
static __inline__ genom_event
loco_codel_task_batt_start(
  struct genom_component_data *self, struct genom_activity *activity)
{
  (void)activity; /* fix -Wunused-parameter */
  genom_event s;

  genom_take_resource(
    self,
    self->resources.control == genom_loco_GetCurrentBattery_controlcb ||
    self->resources.all,

    self->resources.task_batt = InitBattParameters);
  s = InitBattParameters(&(self->ids.batterie), &self->tasks.batt.context);
  genom_give_resource(self, self->resources.task_batt = NULL);

  return s;
}

/* invoke codels according to batt state */
static __inline__ enum genom_activity_status
loco_invoke_task_batt(
  struct genom_component_data *self, struct genom_activity *a)
{
  genom_event s;

  genom_log_debug(
    "task batt invoking task batt %s", a->state);

  if (a->state == loco_start) {
    s = loco_codel_task_batt_start(self, a);
    genom_log_debug("task batt yielded %s", s);
    if (
      0) {
      a->state = s;
      return ACT_RUN;
    }
    if (
      0) {
      a->state = s;
      a->pause = 1;
      return ACT_RUN;
    }
    if (
      s == loco_ether ||
      0) {
      a->state = loco_ether;
      return ACT_ETHER;
    }
    goto ex;
  }

  /* default start, if not already handled above */
  if (a->state == loco_start) {
    a->state = loco_ether;
    return ACT_ETHER;
  }

  /* default stop, if not already handled above */
  if (a->state == loco_stop) {
    genom_interrupted_detail d;

    assert(a->interruptedby);
    strncpy(d.by, a->interruptedby, sizeof(d.by));
    d.by[sizeof(d.by)-1] = *"";
    s = genom_interrupted(&d, &self->tasks.batt.context);
    goto ex;
  }

  /* this cannot happen by construction */
  genom_log_warn(0, "bad state (%s) in task_batt",
                 a->state?a->state : "genom_ok");
  abort();
  /*NOTREACHED*/

ex:
  if (
    s != genom_incompatible_digest_id &&
    s != genom_bad_transition_id &&
    s != genom_interrupted_id &&
    s != genom_serialization_id &&
    s != genom_too_many_activities_id &&
    s != genom_disallowed_id &&
    s != genom_mwerr_id &&
    1) {
    genom_bad_transition_detail d;
    strncpy(d.from, a->state, sizeof(d.from)); d.from[sizeof(d.from)-1] = *"";
    strncpy(d.to, s, sizeof(d.to)); d.to[sizeof(d.to)-1] = *"";
    genom_log_warn(
      0, "bad transition from %s to %s in task batt",
      a->state, s?s:"genom_ok");
    genom_bad_transition(&d, &self->tasks.batt.context);
  }

  a->state = NULL;
  return ACT_ETHER;
}


/* --- service StartBatt ------------------------------------------------ */

/* state start */
static __inline__ genom_event
loco_codel_service_StartBatt_start(
  struct genom_component_data *self, struct genom_activity *activity)
{
  (void)activity; /* fix -Wunused-parameter */
  genom_event s;

  genom_take_resource(
    self,
    self->resources.all,

    self->resources.task_batt = BatteryStart);
  s = BatteryStart(&(self->ids.batterie), &(self->ports.BAT.handle), &self->tasks.batt.context);
  genom_give_resource(self, self->resources.task_batt = NULL);

  return s;
}

/* invoke codels according to StartBatt state */
static __inline__ enum genom_activity_status
loco_invoke_service_StartBatt(
  struct genom_component_data *self, struct genom_activity *a)
{
  genom_event s;

  genom_log_debug(
    "task batt invoking service StartBatt %s", a->state);

  if (a->state == loco_start) {
    s = loco_codel_service_StartBatt_start(self, a);
    genom_log_debug("service StartBatt yielded %s", s);
    if (
      0) {
      a->state = s;
      return ACT_RUN;
    }
    if (
      0) {
      a->state = s;
      a->pause = 1;
      return ACT_RUN;
    }
    if (
      s == loco_ether ||
      0) {
      a->state = loco_ether;
      return ACT_ETHER;
    }
    goto ex;
  }


  /* default stop, if not already handled above */
  if (a->state == loco_stop) {
    genom_interrupted_detail d;

    assert(a->interruptedby);
    strncpy(d.by, a->interruptedby, sizeof(d.by));
    d.by[sizeof(d.by)-1] = *"";
    s = genom_interrupted(&d, &self->tasks.batt.context);
    goto ex;
  }

  /* this cannot happen by construction */
  genom_log_warn(0, "bad state (%s) in service_StartBatt",
                 a->state?a->state : "genom_ok");
  abort();
  /*NOTREACHED*/

ex:
  if (
    s != genom_incompatible_digest_id &&
    s != genom_bad_transition_id &&
    s != genom_interrupted_id &&
    s != genom_serialization_id &&
    s != genom_too_many_activities_id &&
    s != genom_disallowed_id &&
    s != genom_mwerr_id &&
    s != loco_INVALID_DATA_id &&
    1) {
    genom_bad_transition_detail d;
    strncpy(d.from, a->state, sizeof(d.from)); d.from[sizeof(d.from)-1] = *"";
    strncpy(d.to, s, sizeof(d.to)); d.to[sizeof(d.to)-1] = *"";
    genom_log_warn(
      0, "bad transition from %s to %s in service StartBatt",
      a->state, s?s:"genom_ok");
    genom_bad_transition(&d, &self->tasks.batt.context);
  }

  a->state = NULL;
  return ACT_ETHER;
}



/* === task batt ======================================================== */

enum genom_activity_status
genom_loco_batt_invoke(
  struct genom_component_data *self, struct genom_activity *a)
{
  switch(a->sid) {
    case -1:
      return loco_invoke_task_batt(self, a);

    case LOCO_StartBatt_RQSTID:
      return loco_invoke_service_StartBatt(self, a);
  }

  /* must not happen */
  genom_log_warn(0, "bad activity %d in task batt", a->sid);
  abort();
  return ACT_VOID;
}
