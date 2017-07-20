/* --- Generated by genom 2.99.29. Do not edit -------------------------- */

#ifndef H_LOCO_MSGLIB
#define H_LOCO_MSGLIB

#include <stddef.h>

#include "portLib.h"
#include "csLib.h"

#include "serialize.h"


/* --- Service/task id ----------------------------------------------------- */

enum {
  LOCO_abort_activity_RQSTID,
  LOCO_connect_port_RQSTID,
  LOCO_connect_service_RQSTID,
  LOCO_kill_RQSTID,
  LOCO_GetCurrentPosition_RQSTID,
  LOCO_GetCurrentBattery_RQSTID,
  LOCO_GetCurrentMap_RQSTID,
  LOCO_GetCurrentArena_RQSTID,
  LOCO_MoveStop_RQSTID,
  LOCO_BattStop_RQSTID,
  LOCO_StartMove_RQSTID,
  LOCO_StartBatt_RQSTID,

  /* total */
  LOCO_NRQSTID
};

enum {
  loco_move_TASKID,
  loco_batt_TASKID,

  /* total */
  loco_NTASKID
};


/* --- Mailboxes ----------------------------------------------------------- */

/* mailbox buffer size for a message of size "size" */
#define MBOX_BUF_SIZE(size)                             \
  ((size) + 4 - ((size) & 3) + sizeof(LETTER_HDR) + 8)

/* Maximum request size - compilers should optimize this away */
static __inline__ size_t
genom_loco_max_rqst_size(void)
{
  size_t m = 0, s;

  /* input of abort_activity */
  s = 0;
  s += genom_maxserialen_unsigned_long();
  if (m < s) m = s;

  /* input of connect_port */
  s = 0;
  s += genom_maxserialen_string128();
  s += genom_maxserialen_string128();
  if (m < s) m = s;

  /* input of connect_service */
  s = 0;
  s += genom_maxserialen_string128();
  s += genom_maxserialen_string128();
  if (m < s) m = s;

  /* input of kill */
  s = 0;
  if (m < s) m = s;

  /* input of GetCurrentPosition */
  s = 0;
  if (m < s) m = s;

  /* input of GetCurrentBattery */
  s = 0;
  if (m < s) m = s;

  /* input of GetCurrentMap */
  s = 0;
  if (m < s) m = s;

  /* input of GetCurrentArena */
  s = 0;
  if (m < s) m = s;

  /* input of MoveStop */
  s = 0;
  if (m < s) m = s;

  /* input of BattStop */
  s = 0;
  if (m < s) m = s;

  /* input of StartMove */
  s = 0;
  if (m < s) m = s;

  /* input of StartBatt */
  s = 0;
  if (m < s) m = s;

  return m;
}
#define  LOCO_MAX_RQST_SIZE	genom_loco_max_rqst_size()

/* Size of reception mailbox */
#define  LOCO_MBOX_RQST_SIZE                                \
  (MBOX_BUF_SIZE(LOCO_MAX_RQST_SIZE) * SERV_NMAX_RQST_ID)


/* Maximum reply size */
static __inline__ size_t
genom_loco_max_reply_size()
{
  size_t m = 0, s;

  /* output of abort_activity */
  s = 1; /* ok flag */
  if (m < s) m = s;

  /* throws of abort_activity */
  s = sizeof(genom_incompatible_digest_id);
  s += genom_maxserialen_t_genom_incompatible_digest();
  if (m < s) m = s;
  s = sizeof(genom_bad_transition_id);
  s += genom_maxserialen_t_genom_bad_transition();
  if (m < s) m = s;
  s = sizeof(genom_interrupted_id);
  s += genom_maxserialen_t_genom_interrupted();
  if (m < s) m = s;
  s = sizeof(genom_serialization_id);
  s += genom_maxserialen_t_genom_serialization();
  if (m < s) m = s;
  s = sizeof(genom_too_many_activities_id);
  s += genom_maxserialen_t_genom_too_many_activities();
  if (m < s) m = s;
  s = sizeof(genom_disallowed_id);
  s += genom_maxserialen_t_genom_disallowed();
  if (m < s) m = s;
  s = sizeof(genom_mwerr_id);
  s += genom_maxserialen_t_genom_mwerr();
  if (m < s) m = s;
  s = sizeof(genom_no_such_activity_id);
  s += genom_maxserialen_t_genom_no_such_activity();
  if (m < s) m = s;

  /* output of connect_port */
  s = 1; /* ok flag */
  if (m < s) m = s;

  /* throws of connect_port */
  s = sizeof(genom_incompatible_digest_id);
  s += genom_maxserialen_t_genom_incompatible_digest();
  if (m < s) m = s;
  s = sizeof(genom_bad_transition_id);
  s += genom_maxserialen_t_genom_bad_transition();
  if (m < s) m = s;
  s = sizeof(genom_interrupted_id);
  s += genom_maxserialen_t_genom_interrupted();
  if (m < s) m = s;
  s = sizeof(genom_serialization_id);
  s += genom_maxserialen_t_genom_serialization();
  if (m < s) m = s;
  s = sizeof(genom_too_many_activities_id);
  s += genom_maxserialen_t_genom_too_many_activities();
  if (m < s) m = s;
  s = sizeof(genom_disallowed_id);
  s += genom_maxserialen_t_genom_disallowed();
  if (m < s) m = s;
  s = sizeof(genom_mwerr_id);
  s += genom_maxserialen_t_genom_mwerr();
  if (m < s) m = s;
  s = sizeof(genom_no_such_inport_id);
  s += genom_maxserialen_t_genom_no_such_inport();
  if (m < s) m = s;
  s = sizeof(genom_no_such_outport_id);
  s += genom_maxserialen_t_genom_no_such_outport();
  if (m < s) m = s;
  s = sizeof(genom_port_io_id);
  s += genom_maxserialen_t_genom_port_io();
  if (m < s) m = s;

  /* output of connect_service */
  s = 1; /* ok flag */
  if (m < s) m = s;

  /* throws of connect_service */
  s = sizeof(genom_incompatible_digest_id);
  s += genom_maxserialen_t_genom_incompatible_digest();
  if (m < s) m = s;
  s = sizeof(genom_bad_transition_id);
  s += genom_maxserialen_t_genom_bad_transition();
  if (m < s) m = s;
  s = sizeof(genom_interrupted_id);
  s += genom_maxserialen_t_genom_interrupted();
  if (m < s) m = s;
  s = sizeof(genom_serialization_id);
  s += genom_maxserialen_t_genom_serialization();
  if (m < s) m = s;
  s = sizeof(genom_too_many_activities_id);
  s += genom_maxserialen_t_genom_too_many_activities();
  if (m < s) m = s;
  s = sizeof(genom_disallowed_id);
  s += genom_maxserialen_t_genom_disallowed();
  if (m < s) m = s;
  s = sizeof(genom_mwerr_id);
  s += genom_maxserialen_t_genom_mwerr();
  if (m < s) m = s;
  s = sizeof(genom_no_such_remote_id);
  s += genom_maxserialen_t_genom_no_such_remote();
  if (m < s) m = s;
  s = sizeof(genom_no_such_service_id);
  s += genom_maxserialen_t_genom_no_such_service();
  if (m < s) m = s;
  s = sizeof(genom_remote_io_id);
  s += genom_maxserialen_t_genom_remote_io();
  if (m < s) m = s;

  /* output of kill */
  s = 1; /* ok flag */
  if (m < s) m = s;

  /* throws of kill */
  s = sizeof(genom_incompatible_digest_id);
  s += genom_maxserialen_t_genom_incompatible_digest();
  if (m < s) m = s;
  s = sizeof(genom_bad_transition_id);
  s += genom_maxserialen_t_genom_bad_transition();
  if (m < s) m = s;
  s = sizeof(genom_interrupted_id);
  s += genom_maxserialen_t_genom_interrupted();
  if (m < s) m = s;
  s = sizeof(genom_serialization_id);
  s += genom_maxserialen_t_genom_serialization();
  if (m < s) m = s;
  s = sizeof(genom_too_many_activities_id);
  s += genom_maxserialen_t_genom_too_many_activities();
  if (m < s) m = s;
  s = sizeof(genom_disallowed_id);
  s += genom_maxserialen_t_genom_disallowed();
  if (m < s) m = s;
  s = sizeof(genom_mwerr_id);
  s += genom_maxserialen_t_genom_mwerr();
  if (m < s) m = s;

  /* output of GetCurrentPosition */
  s = 1; /* ok flag */
  s += genom_maxserialen_t_camera_robot();
  if (m < s) m = s;

  /* throws of GetCurrentPosition */
  s = sizeof(genom_incompatible_digest_id);
  s += genom_maxserialen_t_genom_incompatible_digest();
  if (m < s) m = s;
  s = sizeof(genom_bad_transition_id);
  s += genom_maxserialen_t_genom_bad_transition();
  if (m < s) m = s;
  s = sizeof(genom_interrupted_id);
  s += genom_maxserialen_t_genom_interrupted();
  if (m < s) m = s;
  s = sizeof(genom_serialization_id);
  s += genom_maxserialen_t_genom_serialization();
  if (m < s) m = s;
  s = sizeof(genom_too_many_activities_id);
  s += genom_maxserialen_t_genom_too_many_activities();
  if (m < s) m = s;
  s = sizeof(genom_disallowed_id);
  s += genom_maxserialen_t_genom_disallowed();
  if (m < s) m = s;
  s = sizeof(genom_mwerr_id);
  s += genom_maxserialen_t_genom_mwerr();
  if (m < s) m = s;

  /* output of GetCurrentBattery */
  s = 1; /* ok flag */
  s += genom_maxserialen_t_loco_data();
  if (m < s) m = s;

  /* throws of GetCurrentBattery */
  s = sizeof(genom_incompatible_digest_id);
  s += genom_maxserialen_t_genom_incompatible_digest();
  if (m < s) m = s;
  s = sizeof(genom_bad_transition_id);
  s += genom_maxserialen_t_genom_bad_transition();
  if (m < s) m = s;
  s = sizeof(genom_interrupted_id);
  s += genom_maxserialen_t_genom_interrupted();
  if (m < s) m = s;
  s = sizeof(genom_serialization_id);
  s += genom_maxserialen_t_genom_serialization();
  if (m < s) m = s;
  s = sizeof(genom_too_many_activities_id);
  s += genom_maxserialen_t_genom_too_many_activities();
  if (m < s) m = s;
  s = sizeof(genom_disallowed_id);
  s += genom_maxserialen_t_genom_disallowed();
  if (m < s) m = s;
  s = sizeof(genom_mwerr_id);
  s += genom_maxserialen_t_genom_mwerr();
  if (m < s) m = s;

  /* output of GetCurrentMap */
  s = 1; /* ok flag */
  s += genom_maxserialen_t_camera_map();
  if (m < s) m = s;

  /* throws of GetCurrentMap */
  s = sizeof(genom_incompatible_digest_id);
  s += genom_maxserialen_t_genom_incompatible_digest();
  if (m < s) m = s;
  s = sizeof(genom_bad_transition_id);
  s += genom_maxserialen_t_genom_bad_transition();
  if (m < s) m = s;
  s = sizeof(genom_interrupted_id);
  s += genom_maxserialen_t_genom_interrupted();
  if (m < s) m = s;
  s = sizeof(genom_serialization_id);
  s += genom_maxserialen_t_genom_serialization();
  if (m < s) m = s;
  s = sizeof(genom_too_many_activities_id);
  s += genom_maxserialen_t_genom_too_many_activities();
  if (m < s) m = s;
  s = sizeof(genom_disallowed_id);
  s += genom_maxserialen_t_genom_disallowed();
  if (m < s) m = s;
  s = sizeof(genom_mwerr_id);
  s += genom_maxserialen_t_genom_mwerr();
  if (m < s) m = s;

  /* output of GetCurrentArena */
  s = 1; /* ok flag */
  s += genom_maxserialen_t_camera_arena();
  if (m < s) m = s;

  /* throws of GetCurrentArena */
  s = sizeof(genom_incompatible_digest_id);
  s += genom_maxserialen_t_genom_incompatible_digest();
  if (m < s) m = s;
  s = sizeof(genom_bad_transition_id);
  s += genom_maxserialen_t_genom_bad_transition();
  if (m < s) m = s;
  s = sizeof(genom_interrupted_id);
  s += genom_maxserialen_t_genom_interrupted();
  if (m < s) m = s;
  s = sizeof(genom_serialization_id);
  s += genom_maxserialen_t_genom_serialization();
  if (m < s) m = s;
  s = sizeof(genom_too_many_activities_id);
  s += genom_maxserialen_t_genom_too_many_activities();
  if (m < s) m = s;
  s = sizeof(genom_disallowed_id);
  s += genom_maxserialen_t_genom_disallowed();
  if (m < s) m = s;
  s = sizeof(genom_mwerr_id);
  s += genom_maxserialen_t_genom_mwerr();
  if (m < s) m = s;

  /* output of MoveStop */
  s = 1; /* ok flag */
  if (m < s) m = s;

  /* throws of MoveStop */
  s = sizeof(genom_incompatible_digest_id);
  s += genom_maxserialen_t_genom_incompatible_digest();
  if (m < s) m = s;
  s = sizeof(genom_bad_transition_id);
  s += genom_maxserialen_t_genom_bad_transition();
  if (m < s) m = s;
  s = sizeof(genom_interrupted_id);
  s += genom_maxserialen_t_genom_interrupted();
  if (m < s) m = s;
  s = sizeof(genom_serialization_id);
  s += genom_maxserialen_t_genom_serialization();
  if (m < s) m = s;
  s = sizeof(genom_too_many_activities_id);
  s += genom_maxserialen_t_genom_too_many_activities();
  if (m < s) m = s;
  s = sizeof(genom_disallowed_id);
  s += genom_maxserialen_t_genom_disallowed();
  if (m < s) m = s;
  s = sizeof(genom_mwerr_id);
  s += genom_maxserialen_t_genom_mwerr();
  if (m < s) m = s;

  /* output of BattStop */
  s = 1; /* ok flag */
  if (m < s) m = s;

  /* throws of BattStop */
  s = sizeof(genom_incompatible_digest_id);
  s += genom_maxserialen_t_genom_incompatible_digest();
  if (m < s) m = s;
  s = sizeof(genom_bad_transition_id);
  s += genom_maxserialen_t_genom_bad_transition();
  if (m < s) m = s;
  s = sizeof(genom_interrupted_id);
  s += genom_maxserialen_t_genom_interrupted();
  if (m < s) m = s;
  s = sizeof(genom_serialization_id);
  s += genom_maxserialen_t_genom_serialization();
  if (m < s) m = s;
  s = sizeof(genom_too_many_activities_id);
  s += genom_maxserialen_t_genom_too_many_activities();
  if (m < s) m = s;
  s = sizeof(genom_disallowed_id);
  s += genom_maxserialen_t_genom_disallowed();
  if (m < s) m = s;
  s = sizeof(genom_mwerr_id);
  s += genom_maxserialen_t_genom_mwerr();
  if (m < s) m = s;

  /* output of StartMove */
  s = 1; /* ok flag */
  if (m < s) m = s;

  /* throws of StartMove */
  s = sizeof(genom_incompatible_digest_id);
  s += genom_maxserialen_t_genom_incompatible_digest();
  if (m < s) m = s;
  s = sizeof(genom_bad_transition_id);
  s += genom_maxserialen_t_genom_bad_transition();
  if (m < s) m = s;
  s = sizeof(genom_interrupted_id);
  s += genom_maxserialen_t_genom_interrupted();
  if (m < s) m = s;
  s = sizeof(genom_serialization_id);
  s += genom_maxserialen_t_genom_serialization();
  if (m < s) m = s;
  s = sizeof(genom_too_many_activities_id);
  s += genom_maxserialen_t_genom_too_many_activities();
  if (m < s) m = s;
  s = sizeof(genom_disallowed_id);
  s += genom_maxserialen_t_genom_disallowed();
  if (m < s) m = s;
  s = sizeof(genom_mwerr_id);
  s += genom_maxserialen_t_genom_mwerr();
  if (m < s) m = s;
  s = sizeof(loco_INVALID_ORDER_id);
  s += genom_maxserialen_t_loco_INVALID_ORDER();
  if (m < s) m = s;

  /* output of StartBatt */
  s = 1; /* ok flag */
  if (m < s) m = s;

  /* throws of StartBatt */
  s = sizeof(genom_incompatible_digest_id);
  s += genom_maxserialen_t_genom_incompatible_digest();
  if (m < s) m = s;
  s = sizeof(genom_bad_transition_id);
  s += genom_maxserialen_t_genom_bad_transition();
  if (m < s) m = s;
  s = sizeof(genom_interrupted_id);
  s += genom_maxserialen_t_genom_interrupted();
  if (m < s) m = s;
  s = sizeof(genom_serialization_id);
  s += genom_maxserialen_t_genom_serialization();
  if (m < s) m = s;
  s = sizeof(genom_too_many_activities_id);
  s += genom_maxserialen_t_genom_too_many_activities();
  if (m < s) m = s;
  s = sizeof(genom_disallowed_id);
  s += genom_maxserialen_t_genom_disallowed();
  if (m < s) m = s;
  s = sizeof(genom_mwerr_id);
  s += genom_maxserialen_t_genom_mwerr();
  if (m < s) m = s;
  s = sizeof(loco_INVALID_DATA_id);
  s += genom_maxserialen_t_loco_INVALID_DATA();
  if (m < s) m = s;


  s = sizeof(genom_unkex_id) + sizeof(genom_unkex_detail);
  if (m < s) m = s;
  s = sizeof(genom_syserr_id) + sizeof(genom_syserr_detail);
  if (m < s) m = s;
  return m;
}
#define  LOCO_MAX_REPLY_SIZE		genom_loco_max_reply_size()
#define  LOCO_MAX_INTERMED_REPLY_SIZE	sizeof(int)

/* Size of reply mbox (clients) */
#define  LOCO_CLIENT_MBOX_REPLY_SIZE        	\
  ((MBOX_BUF_SIZE(LOCO_MAX_REPLY_SIZE) +		\
    MBOX_BUF_SIZE(LOCO_MAX_INTERMED_REPLY_SIZE))	\
   * CLIENT_NMAX_RQST_ID)

#endif /* H_LOCO_MSGLIB */
