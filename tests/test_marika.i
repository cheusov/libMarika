#ifndef CONCAT
#define CONCAT(a, b, c) a ## b ## c
#define CONCAT_EXPANDED(a, b, c) CONCAT(a, b, c)
#endif

#define TEST_MARIKA CONCAT_EXPANDED(test_mar, NUM, _)
#define TEST_SANITY CONCAT_EXPANDED(test_sanity, NUM, _)
#define TEST_PRINT CONCAT_EXPANDED(test_mar, NUM, print)
#define TEST_COUNT CONCAT_EXPANDED(test_count, NUM, _)

#define SANITY CONCAT_EXPANDED(mar, NUM, sanity)
#define TEST  CONCAT_EXPANDED(mar, NUM, test)
#define FIRST CONCAT_EXPANDED(mar, NUM, first)
#define LAST  CONCAT_EXPANDED(mar, NUM, last)
#define NEXT  CONCAT_EXPANDED(mar, NUM, next)
#define PREV  CONCAT_EXPANDED(mar, NUM, prev)
#define SIZE  CONCAT_EXPANDED(mar, NUM, size)
#define COUNT CONCAT_EXPANDED(mar, NUM, count)
#define MEMUSED CONCAT_EXPANDED(mar, NUM, memused)
#define SET   CONCAT_EXPANDED(mar, NUM, set)
#define FREE  CONCAT_EXPANDED(mar, NUM, free)
#define PRINT CONCAT_EXPANDED(mar, NUM, print)

static size_t TEST_COUNT(void* top, KEY_TYPE key1, KEY_TYPE key2) {
	// slow implementation
	size_t count = 0;
	for (int ret = FIRST(top, &key1); ret != 0 && key1 <= key2; ret = NEXT(top, &key1)) {
		++count;
	}
	return count;
}

static void TEST_PRINT(void* node) {
	if (!node)
		return;

	KEY_TYPE key = MIN_KEY;
	int ret;
	for (ret = FIRST(node, &key); ret != 0; ret = NEXT(node, &key)) {
		printf("found key: %" PRIu64 "\n", (uint64_t)key);
	}
	printf("\n");
}

static void TEST_SANITY (void* node) {
	if (!node)
		return;

	int ret;

	//
	assert(SIZE(node) == COUNT(node, MIN_KEY, MAX_KEY));

	// first/next
	KEY_TYPE key = MIN_KEY;
	size_t count = 0;
	for (ret = FIRST(node, &key); ret != 0; ret = NEXT(node, &key)) {
		assert(TEST(node, key));
		++count;
	}
	key = (KEY_TYPE) MAX_KEY;
	assert(!NEXT(node, &key));
	assert(count == SIZE(node));

	// last/prev
	key = (KEY_TYPE) MAX_KEY;
	count = 0;
	for (ret = LAST(node, &key); ret != 0; ret = PREV(node, &key)) {
		assert(TEST(node, key));
		++count;
	}
	key = (KEY_TYPE) MIN_KEY;
	assert(!PREV(node, &key));
	assert(count == SIZE(node));
}

static void TEST_MARIKA(uint32_t* keys, size_t count) {
	void* marika = NULL;

	marika_error_t err;
	memset(&err, 0, sizeof(err));

	assert(!SANITY(marika, NULL));
	assert(!TEST(marika, 100500));

	KEY_TYPE key = 100500;
	assert(!FIRST(marika, &key));
	assert(!NEXT(marika, &key));
	assert(!LAST(marika, &key));
	assert(!PREV(marika, &key));
	PRINT(stdout, marika);
	assert(0 == MEMUSED(marika));
	assert(0 == SIZE(marika));
	assert(0 == COUNT(marika, MIN_KEY, MAX_KEY));

	FREE(&marika);
	for (int k = 1; k <= iterations; ++k) {
		shuffle_array(keys, count);

		for (int i = 0; i < count; ++i) {
			SET(&marika, keys[i], &err);
			if (err.errno) {
				fprintf(stderr, "errno: %u\n", (unsigned)err.errno);
				exit(1);
			}

			if ((i % consistency) == 0) {
				assert(!SANITY(marika, &err));
				if (err.errno) {
					fprintf(stderr, "errno: %u\n", (unsigned)err.errno);
					exit(1);
				}
				TEST_SANITY (marika);
				assert(TEST_COUNT(marika, keys[0], keys[1]) == COUNT(marika, keys[0], keys[1]));
				assert(TEST_COUNT(marika, keys[1], keys[0]) == COUNT(marika, keys[1], keys[0]));
			}
		}

		TEST_SANITY(marika);
		//	test_mar4Uprint(marika);

		if (!k)
			printf("memused: %zd\n", MEMUSED(marika));

		FREE(&marika);
		printf("\r%d", k);
	}
	printf("\n");
}

#undef NUM
#undef KEY_TYPE
#undef MIN_KEY
#undef MAX_KEY
