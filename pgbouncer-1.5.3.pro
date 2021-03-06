######################################################################
# Automatically generated by qmake (2.01a) ?? ?? 18 21:39:34 2016
######################################################################

TEMPLATE = app
TARGET = 
DEPENDPATH += . include src test win32 lib\usual
INCLUDEPATH += .

# Input
HEADERS += include/admin.h \
           include/bouncer.h \
           include/client.h \
           include/dnslookup.h \
           include/iobuf.h \
           include/janitor.h \
           include/loader.h \
           include/objects.h \
           include/pktbuf.h \
           include/pooler.h \
           include/proto.h \
           include/sbuf.h \
           include/server.h \
           include/stats.h \
           include/system.h \
           include/takeover.h \
           include/util.h \
           include/varcache.h \
           win32/win32support.h \
           lib/usual/aatree.h \
           lib/usual/base.h \
           lib/usual/base_win32.h \
           lib/usual/bits.h \
           lib/usual/cbtree.h \
           lib/usual/cfparser.h \
           lib/usual/crc32.h \
           lib/usual/ctype.h \
           lib/usual/cxalloc.h \
           lib/usual/cxextra.h \
           lib/usual/daemon.h \
           lib/usual/endian.h \
           lib/usual/err.h \
           lib/usual/event.h \
           lib/usual/fileutil.h \
           lib/usual/getopt.h \
           lib/usual/hashtab-impl.h \
           lib/usual/heap.h \
           lib/usual/hmac.h \
           lib/usual/list.h \
           lib/usual/logging.h \
           lib/usual/lookup3.h \
           lib/usual/mbuf.h \
           lib/usual/md5.h \
           lib/usual/mdict.h \
           lib/usual/mempool.h \
           lib/usual/misc.h \
           lib/usual/netdb.h \
           lib/usual/pgsocket.h \
           lib/usual/pgutil.h \
           lib/usual/pgutil_kwlookup.h \
           lib/usual/pthread.h \
           lib/usual/regex.h \
           lib/usual/safeio.h \
           lib/usual/sha1.h \
           lib/usual/shlist.h \
           lib/usual/signal.h \
           lib/usual/slab.h \
           lib/usual/socket.h \
           lib/usual/socket_win32.h \
           lib/usual/statlist.h \
           lib/usual/string.h \
           lib/usual/strpool.h \
           lib/usual/time.h \
           lib/usual/utf8.h \
    src/send_request.h \
    include/send_request.h \
    include/hf_list.h
SOURCES += src/admin.c \
           src/client.c \
           src/dnslookup.c \
           src/janitor.c \
           src/loader.c \
           src/main.c \
           src/objects.c \
           src/pktbuf.c \
           src/pooler.c \
           src/proto.c \
           src/sbuf.c \
           src/server.c \
           src/stats.c \
           src/system.c \
           src/takeover.c \
           src/util.c \
           src/varcache.c \
           test/asynctest.c \
           win32/pgbevent.c \
           win32/win32support.c \
           lib/usual/aatree.c \
           lib/usual/base.c \
           lib/usual/cbtree.c \
           lib/usual/cfparser.c \
           lib/usual/crc32.c \
           lib/usual/cxalloc.c \
           lib/usual/cxextra.c \
           lib/usual/daemon.c \
           lib/usual/err.c \
           lib/usual/event.c \
           lib/usual/fileutil.c \
           lib/usual/getopt.c \
           lib/usual/heap.c \
           lib/usual/hmac.c \
           lib/usual/list.c \
           lib/usual/logging.c \
           lib/usual/lookup3.c \
           lib/usual/mbuf.c \
           lib/usual/md5.c \
           lib/usual/mdict.c \
           lib/usual/mempool.c \
           lib/usual/netdb.c \
           lib/usual/pgsocket.c \
           lib/usual/pgutil.c \
           lib/usual/pthread.c \
           lib/usual/regex.c \
           lib/usual/safeio.c \
           lib/usual/sha1.c \
           lib/usual/signal.c \
           lib/usual/slab.c \
           lib/usual/socket.c \
           lib/usual/socket_ntop.c \
           lib/usual/socket_pton.c \
           lib/usual/string.c \
           lib/usual/strpool.c \
           lib/usual/time.c \
           lib/usual/utf8.c \
    src/send_request.c \
    src/hf_list.c


INCLUDEPATH += "F:\C-C++\pgbouncer-1.5.3\include"
INCLUDEPATH += "F:\C-C++\pgbouncer-1.5.3\lib"

INCLUDEPATH +="G:\Program Files (x86)\libstrophe-master"
