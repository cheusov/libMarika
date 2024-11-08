LIB           =	marika
SRCS          = \
   marika4U.c marika8U.c marika4S.c marika8S.c \
   marika4U4U.c marika4S4U.c marika4U4S.c marika4S4S.c \
   marika8U8U.c marika8S8U.c marika8U8S.c marika8S8S.c\
   marika4U8U.c marika4S8U.c marika4U8S.c marika4S8S.c \
   marika8U4U.c marika8S4U.c marika8U4S.c marika8S4S.c

MAN           =	marika_set.3 marika_map.3

DPSRC        +=	marika.h

INCS          =	marika.h

MKC_CHECK_SIZEOF =	void* int long

SHLIB_MAJOR   =	0
SHLIB_MINOR   =	0

EXPORT_SYMBOLS =	export.sym

MKC_FEATURES +=	macro

marika.h: marika_tmpl.h
	sed -e 's/sizeof\[void[*]\]/${SIZEOF.voidP}/g' \
	    -e 's/sizeof\[int\]/${SIZEOF.int}/g' \
	    -e 's/sizeof\[long\]/${SIZEOF.long}/g' \
	   marika_tmpl.h > $@

CLEANFILES +=	marika.h ${MAN}

.for k in 4U 4S 8U 8S I U L LU
marika${v}.os marika${k}.o: impl.i marika.h
. for v in 4U 4S 8U 8S I U L LU P
marika${k}${v}.os marika${k}${v}.o: impl.i marika.h
. endfor
.endfor

.include <mkc.mk>
