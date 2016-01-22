#ifndef SEND_REQUEST_H
#define SEND_REQUEST_H


#include <unistd.h>
#include <strophe.h>



#define  AUTH_NS    "hf.safe.auth"
#define     RES_YES     1
#define     RES_NO      2
#define     GetRes(X)   (X == 1 ? "Yes" : "No")


struct xmpp_global
{
    xmpp_ctx_t          *ctx;
    xmpp_conn_t         *conn;
    int                 replyed;
    int                 bconnected;
    char                name[64];
    char                passwd[64];
};


extern struct xmpp_global  xmpp_args;

void    init_xmpp(void);

bool sendAuth(const char *to, const char *app);
int handle_reply(xmpp_conn_t * const conn,
         xmpp_stanza_t * const stanza,
         void * const userdata);

void conn_handler(xmpp_conn_t *const conn, const xmpp_conn_event_t status,
                  const int error,xmpp_stream_error_t *const stream_error,
                  void *const userdata);

void *thread_call(void *arg);


#endif // SEND_REQUEST_H
