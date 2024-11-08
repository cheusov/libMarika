PROGS              =	test_marika test_play

MKC_FEATURES      +=	posix_getopt

MKINSTALL          =	no

CFLAGS.check      +=	-Wno-unused-function

test_marika.op test_marika.os test_marika.o: test_marika.i

test: test_sets

test_sets: .PHONY
.for b in 4U 8U 4S 8S
. for seed iterations count C in \
    1 10000 500 0 \
    1 10000  50 1
	@set -e; \
	${ld_lib_path}; \
	cmd="test_marika -s${seed} -${b} -t${iterations} -c${count} -C${C}"; \
	echo "$$cmd" 1>&2; ${.OBJDIR}/$$cmd
. endfor
.endfor

.include <mkc.mk>
