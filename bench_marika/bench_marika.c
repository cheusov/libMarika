#include <mkc_posix_getopt.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>

#include <marika_tmpl.h>

static void usage(void) {
	fprintf(stderr, "\
usage: bench_marika [OPTIONS]\n\
OPTIONS:\n\
   -h            - display this screen\n\
   -4            - use mar4U* functions\n\
   -8            - use mar8U* functions\n\
   -c count      - insert <count> items\n\
\n\
Either -4 or -8 must be applied\n\
Option -c must be applied\n\
");
}

static uint64_t user_time(void) {
	struct rusage r_usage;
	if (getrusage(RUSAGE_SELF, &r_usage)) {
		perror("getrusage(2) failed");
		exit(1);
	}
	return r_usage.ru_utime.tv_sec * 1000000uL + r_usage.ru_utime.tv_usec;
}

int main(int argc, char **argv) {
	int opt;
	int test_uint32 = 0;
	int test_uint64 = 0;
	int test_count = 0;

	while ((opt = getopt(argc, argv, "48c:h")) != -1) {
		switch (opt) {
			case '4':
				test_uint32 = 1;
				break;
			case '8':
				test_uint64 = 1;
				break;
			case 'c':
				test_count = atoi(optarg);
				break;
			case 'h':
				usage();
				return EXIT_SUCCESS;
			default: /* '?' */
				usage();
				exit(EXIT_FAILURE);
		}
	}
	argc -= optind;
	argv += optind;

	if (!test_uint32 && !test_uint64) {
		fprintf(stderr, "Either -4 or -8 must be applied\n");
		return EXIT_FAILURE;
	}

	if (!test_count) {
		fprintf(stderr, "Option -c must be applied\n");
		return EXIT_FAILURE;
	}

	// generate keys
	uint32_t *keys = calloc(test_count, sizeof(uint32_t));
	srand(100500);
	for (int i = 0; i < test_count; ++i) {
		keys[i] = rand();
	}

	// inserting
	uint64_t before = user_time();
	void* marika = NULL;
	marika_error_t err;
	memset(&err, 0, sizeof(err));
	size_t counter = 0;
	if (test_uint32) {
		for (int i = 0; i < test_count; ++i) {
			counter += mar4Uset(&marika, keys[i], &err);
			if (err.errno) {
				fprintf(stderr, "errno: %u\n", (unsigned)err.errno);
				exit(1);
			}
		}
	} else if (test_uint64) {
		for (int i = 0; i < test_count; ++i) {
			counter += mar8Uset(&marika, keys[i], &err);
			if (err.errno) {
				fprintf(stderr, "errno: %u\n", (unsigned)err.errno);
				exit(1);
			}
		}
	}
	printf("time: %zd milliseconds\n", (user_time() - before) / 1000);

	// freeing keys
	free(keys);

//	fprintf(stderr, "marika=%p\n", marika);

	//	print_tree(marika, 0);
	memset(&err, 0, sizeof(err));
	printf("total calculated counter=%zd\n", counter);
	if (test_uint32) {
		if (mar4Usanity(marika, &err)) {
			fprintf(stderr, "sanity check failed: %d\n", err.errno);
			return 1;
		}
		printf("mar4Usize: %zd\n", mar4Usize(marika));
		printf("mar4Umemused: %zd\n", mar4Umemused(marika));
		mar4Ufree(&marika);
	} else if (test_uint64) {
		if (mar8Usanity(marika, &err)) {
			fprintf(stderr, "sanity check failed: %d\n", err.errno);
			return 1;
		}
		printf("mar8Usize: %zd\n", mar8Usize(marika));
		printf("mar8Umemused: %zd\n", mar8Umemused(marika));
		mar8Ufree(&marika);
	}

	return 0;
}
