PROG               =	bench_marika
#SRCS.bench_marika  =	bench_marika.c

CPPFLAGS          +=	-I../libmarika
LDFLAGS           +=	-Wl,-rpath,${OBJDIR_libmarika}

MKC_FEATURES      +=	posix_getopt

MKINSTALL          =	no

.include <mkc.mk>
