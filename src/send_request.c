#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <strophe.h>
#include <string.h>
#include "send_request.h"

#include "bouncer.h"

 
struct xmpp_global  xmpp_args;

void init_xmpp(void)
{
    int i = 0;
    pthread_t thread;

    xmpp_args.bconnected = 0;

    pthread_create(&thread,NULL,thread_call,NULL);
    while ( xmpp_args.bconnected == 0)
    {
        usleep(1000);
        i++;
        if ( i > 1000 * 10)
        {
            break;
        }
    }
}

const char *sendAuth(const char *to, const char *app)
{
    char    cto[128] = {0};
    const char *domain;
    int     i = 0;

    xmpp_stanza_t *iq , *auth;
    xmpp_args.replyed = 0;

    iq = xmpp_stanza_new(xmpp_args.ctx);

    /*create to user*/
    domain = getenv("DOMAIN");
    if ( NULL == domain ||strlen(domain) < 1)
    {
        return GetRes(RES_NO);
    }
    sprintf(cto,"%s@%s/safe",to,domain);
    log_debug("send to user:%s\n",cto);

    /*create iq stanza*/
    xmpp_stanza_set_name(iq,"iq");
    xmpp_stanza_set_to(iq,cto);
    xmpp_stanza_set_type(iq,"get");

    /*create auth stanza*/
    auth = xmpp_stanza_new(xmpp_args.ctx);
    xmpp_stanza_set_name(auth,"auth");
    xmpp_stanza_set_ns(auth,AUTH_NS);
    xmpp_stanza_set_attribute(auth,"name",app);

    /*combine two stanza*/
    xmpp_stanza_add_child(iq,auth);

    /*send request*/
    xmpp_send(xmpp_args.conn,iq);
    while ( xmpp_args.replyed == 0 )
    {
        usleep(1000);
        i++;
        if ( i > 1000*10)
        {
            xmpp_args.replyed = RES_NO;
            break;
        }
    }
    return GetRes(xmpp_args.replyed);
}


void *thread_call(void *arg)
{
    long flags = 0;
    char jid[128] = {0};
    const char *domain,*host,*usr,*pwd;
    xmpp_log_t *log;

    domain = getenv("DOMAIN");
    host = getenv("HOSTIP");
    usr = getenv("USR");
    pwd = getenv("PASSWD");

    log_debug("domain=%s host=%s usr=%s",domain,host,usr);

    sprintf(jid,"%s@%s/bouncer",usr,domain);
    /*init lib*/
    xmpp_initialize();

    /*create context*/
    log = xmpp_get_default_logger(XMPP_LEVEL_DEBUG);
    //_ctx = xmpp_ctx_new(NULL,log);
    xmpp_args.ctx = xmpp_ctx_new(NULL,log);

    /*create connection*/
    //_conn = xmpp_conn_new(_ctx);
    xmpp_args.conn = xmpp_conn_new(xmpp_args.ctx);

    /*configure connection properties*/
    flags |= XMPP_CONN_FLAG_DISABLE_TLS;
    xmpp_conn_set_flags(xmpp_args.conn,flags);

    xmpp_conn_set_jid(xmpp_args.conn,jid);
    xmpp_conn_set_pass(xmpp_args.conn,pwd);

    xmpp_connect_client(xmpp_args.conn,host,0,conn_handler,xmpp_args.ctx);

    xmpp_run(xmpp_args.ctx);
    xmpp_conn_release(xmpp_args.conn);
    xmpp_shutdown();
    return NULL;
}


int handle_reply(xmpp_conn_t * const conn,
         xmpp_stanza_t * const stanza,
         void * const userdata)
{

    xmpp_stanza_t *iq,*ping;
    xmpp_ctx_t    *ctx = (xmpp_ctx_t*)userdata;

    char *type,*id,*from;


    log_debug("Receive New Stanza\n");


    id = xmpp_stanza_get_id(stanza);
    type = xmpp_stanza_get_type(stanza);
    from = xmpp_stanza_get_from(stanza);

    if (strcmp(type, "error") == 0)
        log_debug("ERROR: query failed\n");
    else
    {
        xmpp_stanza_t *chld = xmpp_stanza_get_child_by_name(stanza,"auth");
        if ( NULL == chld)
        {
            log_debug("Not auth iq\n");
            ping = xmpp_stanza_get_child_by_name(stanza,"ping");
            if( NULL != ping)
            {
                iq = xmpp_stanza_new(ctx);
                xmpp_stanza_set_name(iq,"iq");
                xmpp_stanza_set_type(iq,"result");
                if ( NULL != id)
                {
                    xmpp_stanza_set_id(iq,id);
                }
                if ( NULL != id)
                {
                    xmpp_stanza_set_to(iq,from);
                }
                xmpp_send(conn,iq);
                xmpp_stanza_release(iq);
            }
        }else
        {
            char *ret = xmpp_stanza_get_attribute(chld,"result");
            log_info("Auth Result:%s\n",ret);
            if ( strcmp(ret,"Yes") == 0 )
            {
                xmpp_args.replyed = RES_YES;
            }else{
                xmpp_args.replyed = RES_NO;
            }

        }
    }

    /* disconnect */

    return 1;
}

void conn_handler(xmpp_conn_t *const conn, const xmpp_conn_event_t status,
                  const int error,xmpp_stream_error_t *const stream_error,
                  void *const userdata)
{
    xmpp_ctx_t *ctx = (xmpp_ctx_t*)userdata;
    xmpp_stanza_t  *pres;
    //bconnected = 1;
    xmpp_args.bconnected = 1;
    if ( status == XMPP_CONN_CONNECT )
    {
        log_info("DEBUG:connected\n");
    }

    pres = xmpp_stanza_new(ctx);
    xmpp_stanza_set_name(pres,"presence");
    xmpp_send(conn,pres);
    xmpp_stanza_release(pres);
    xmpp_handler_add(conn,handle_reply,NULL,"iq",NULL,ctx);
//    xmpp_handler_add(conn,message_handler,NULL,"message",NULL,ctx);

}

