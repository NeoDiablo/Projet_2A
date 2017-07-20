/*
 * Copyright (c) 2012-2014 LAAS/CNRS
 * All rights reserved.
 *
 * Redistribution and use  in source  and binary  forms,  with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *   1. Redistributions of  source  code must retain the  above copyright
 *      notice and this list of conditions.
 *   2. Redistributions in binary form must reproduce the above copyright
 *      notice and  this list of  conditions in the  documentation and/or
 *      other materials provided with the distribution.
 *
 *                                      Anthony Mallet on Thu Mar 15 2012
 */
#ifndef H_CCLIENT_PRIVATE
#define H_CCLIENT_PRIVATE

#include <stddef.h>
#include <stdint.h>

#include "csLib.h"

#include "genom3/c/client.h"

struct pocolibs_options {
  size_t varmsg_maxsize;
  char *instance;
};

struct genom_context_data {
  genom_client h;

  genom_event ex;
  void *exdetail;
  size_t exsize;
};

struct genom_client_s {
  struct genom_context_iface context;
  struct genom_context_data context_data;

  char *instance;
  CLIENT_ID csid;

  struct genom_client_request {
    const struct genom_service_info *info;
    int rid, aid;
    int status;
    genom_event report;
    void *output;
    void *exdetail;
    void (*exfini)(void *);
    int	(*decode)(char *, int, char *, int);
    genom_request_cb sentcb, donecb;
    void *cb_data;
  } *active_rqst;
  int nactive, next;
};

extern const struct genom_client_option genom_pocolibs_options[];

genom_event	pocolibs_init(genom_client h, size_t mboxsize);
void		pocolibs_fini(void);
genom_event	pocolibs_getopt(genom_client h, int argc, char *argv[],
                        struct pocolibs_options *opts);

int		pocolibs_eventfd(void);
const struct genom_service_info *
		pocolibs_service_info(genom_client h, int rqstid);
genom_event	pocolibs_waitevent(genom_client h);
genom_event	pocolibs_waitack(genom_client h, int rqstid);
genom_event	pocolibs_waitterm(genom_client h, int rqstid);
int		pocolibs_done(genom_client h, int rqstid);
genom_event	pocolibs_result(genom_client h, int rqstid,
                        genom_event *report, void **output, void **exdetail);
genom_event	pocolibs_clean(genom_client h, int rqstid);
genom_event	pocolibs_doevents(genom_client h);

genom_event	pocolibs_newrqst(genom_client h, size_t outsize, int *rqstid);

genom_event	genom_pocolibs_client_raise(genom_event ex, void *detail,
                        size_t size, genom_context self);
const void *	genom_pocolibs_client_raised(genom_event *ex,
                        genom_context self);

#endif /* H_CCLIENT_PRIVATE */
