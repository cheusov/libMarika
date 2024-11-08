#ifdef _NDEBUG
#undef _NDEBUG
#endif

#include <mkc_posix_getopt.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <inttypes.h>

#include <marika_tmpl.h>

static void shuffle_array(uint32_t *keys, size_t count) {
	for (int i = 0; i < count; ++i) {
		int rnd = rand() % count;

		uint32_t tmp = keys[i];
		keys[i] = keys[rnd];
		keys[rnd] = tmp;
	}
}

static void generate_random_values(uint32_t* keys, size_t count) {
	for (int i = 0; i < count; ++i) {
		keys[i] = rand() % 5000;
//		printf("keys[%d]=%" PRIu64 "\n", i, (uint64_t)keys[i]);
	}
}

static void usage(void) {
	fprintf(stderr, "\
usage: test_marika [OPTIONS]\n\
OPTIONS:\n\
   -h                - Display this screen\n\
   -4                - Use mar4* functions\n\
   -8                - Use mar8* functions\n\
   -t <iterations>   - Repeat tests iterations times\n\
   -c <keys>         - Add count keys to the set\n\
   -s <seed>         - Initial seed for PRN, current time by default\n\
   -C <consistency>  - Check B-Tree correctness every <consistency>\n\
                       inserted items, The default is 50\n\
   -U                - Use unsigned key. This is the default\n\
   -S                - Use signed key. The default is unsigned key\n\
\n\
Either -4 or -8 must be applied.\n\
-t must be applied and must be positive.\n\
-c must be applied and must be positive.\n\
-C must be applied and must be positive.\n\
");
}

static int iterations = 0;
static int consistency = 50;

#define NUM   4U
#define KEY_TYPE uint32_t
#define MIN_KEY 0
#define MAX_KEY (KEY_TYPE)-1
#include "test_marika.i"

#define NUM   4S
#define KEY_TYPE int32_t
#define MIN_KEY 0x80000000
#define MAX_KEY 0x7FFFFFFF
#include "test_marika.i"

#define NUM   8U
#define KEY_TYPE uint64_t
#define MIN_KEY 0
#define MAX_KEY (KEY_TYPE)-1
#include "test_marika.i"

#define NUM   8S
#define KEY_TYPE int64_t
#define MIN_KEY 0x8000000000000000
#define MAX_KEY 0x7FFFFFFFFFFFFFFF
#include "test_marika.i"

int main(int argc, char **argv) {
	int opt;
	int count = 0;
	int test_uint32 = 0;
	int test_uint64 = 0;
	unsigned seed = (unsigned)time(NULL);
	int signed_key = 0;

	while (opt = getopt(argc, argv, "48C:c:hSs:t:U"), opt != -1) {
		switch (opt) {
			case '4':
				test_uint32 = 1;
				break;
			case '8':
				test_uint64 = 1;
				break;
			case 'C':
				{
					int value = atoi(optarg);
					if (value)
						consistency = value;
				}
				break;
			case 'c':
				count = atoi(optarg);
				break;
			case 'h':
				usage();
				return EXIT_SUCCESS;
			case 'S':
				signed_key = 1;
				break;
			case 's':
				{
					int seconds = atoi(optarg);
					if (seconds)
						seed = seconds;
				}
				break;
			case 't':
				iterations = atoi(optarg);
				break;
			case 'U':
				signed_key = 0;
				break;
			default: /* '?' */
				usage();
				exit(EXIT_FAILURE);
		}
	}
	argc -= optind;
	argv += optind;

	if (!test_uint32 && !test_uint64) {
		fprintf(stderr, "Either -4 or -8 must be applied\n");
		usage();
		return EXIT_FAILURE;
	}

	if (iterations <= 0) {
		fprintf(stderr, "Option -t must be applied and must be positive\n");
		usage();
		return EXIT_FAILURE;
	}

	if (count <= 0) {
		fprintf(stderr, "Option -c must be applied and must be positive\n");
		usage();
		return EXIT_FAILURE;
	}

	if (consistency <= 0) {
		fprintf(stderr, "Option -C must be applied and must be positive\n");
		usage();
		return EXIT_FAILURE;
	}

	// generate keys
	uint32_t *keys = calloc(count, sizeof(uint32_t));
	srand(seed);
	generate_random_values(keys, count);

	//
	if (test_uint32) {
		if (signed_key)
			test_mar4S_(keys, count);
		else
			test_mar4U_(keys, count);
	} else if (test_uint64) {
		if (signed_key)
			test_mar8S_(keys, count);
		else
			test_mar8U_(keys, count);
	}

	free(keys);
	return 0;
}
