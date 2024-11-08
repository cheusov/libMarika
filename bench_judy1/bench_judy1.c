#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <getopt.h>
#include <sys/resource.h>
#include <Judy.h>

typedef uint32_t mkey_t;

static void usage(void) {
	fprintf(stderr, "\
usage: bench_judy1 [OPTIONS]\n\
OPTIONS:\n\
   -h            - display this screen\n\
   -c count      - insert <count> items\n\
\n\
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
	int test_count = 0;

	while ((opt = getopt(argc, argv, "c:h")) != -1) {
		switch (opt) {
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

	if (!test_count) {
		fprintf(stderr, "Option -c must be applied\n");
		return EXIT_FAILURE;
	}

	void* key_set = NULL;
	mkey_t *keys = (mkey_t*) calloc(test_count, sizeof(mkey_t));
	srand(100500);
	for (int i = 0; i < test_count; ++i) {
		keys[i] = rand();
	}
	uint64_t before = user_time();
	for (int i = 0; i < test_count; ++i) {
		Judy1Set(&key_set, keys[i], NULL);
	}
	free(keys);
	printf("time: %zu milliseconds\n", (user_time() - before) / 1000);
	printf("total keys: %zu\n", Judy1Count(key_set, 0, -1, NULL));
	printf("Judy1MemUsed: %zu\n", Judy1MemUsed(key_set));

//	for (auto v: key_set) {
//		printf("v=%zu\n", v);
//	}
//	print_tree(top, 0);
}
