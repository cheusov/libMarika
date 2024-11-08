LIBDEPS     =	libmarika:bench_marika libmarika:tests libmarika:examples
SUBPRJ     +=	bench_std_set:bench bench_std_unordered_set:bench bench_judy1:bench bench_marika:bench

SUBPRJ_DFLT =	libmarika bench_marika examples

NODEPS     +=	test-libmarika:*  test-bench_*:*
NODEPS     +=	install-tests:*   install-bench_*:* install-examples:*

test: test-tests
test-tests: all-tests
test-examples: all-examples

MKC_REQD    =	0.34.0

.include "help.mk"
.include "use.mk"
.include <mkc.mk>
