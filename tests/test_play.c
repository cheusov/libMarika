#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <marika_tmpl.h>

static void test1_mar8Sprint(void* node) {
	if (!node)
		return;

	int64_t key = 0;
	int ret;
	for (ret = mar8Sfirst(node, &key); ret != 0; ret = mar8Snext(node, &key)) {
		printf("found 64-bit key: %" PRId64 "\n", (int64_t)key);
	}
	printf("\n");
}

static void test1_mar8Uprint(void* node) {
	if (!node)
		return;

	uint64_t key = 0;
	int ret;
	for (ret = mar8Ufirst(node, &key); ret != 0; ret = mar8Unext(node, &key)) {
		printf("found 64-bit key: %" PRIu64 "\n", (uint64_t)key);
	}
	printf("\n");
}

static void test1_mar4Sprint(void* node) {
	if (!node)
		return;

	int32_t key = 0;
	int ret;
	for (ret = mar4Sfirst(node, &key); ret != 0; ret = mar4Snext(node, &key)) {
		printf("found 64-bit key: %" PRId32 "\n", (int32_t)key);
	}
	printf("\n");
}

static void test1_mar4Uprint(void* node) {
	if (!node)
		return;

	uint32_t key = 0;
	int ret;
	for (ret = mar4Ufirst(node, &key); ret != 0; ret = mar4Unext(node, &key)) {
		printf("found 64-bit key: %" PRIu32 "\n", (uint32_t)key);
	}
	printf("\n");
}

static void test2_mar8Sprint(void* node) {
	if (!node)
		return;

	int64_t key = -1;
	int ret;
	for (ret = mar8Slast(node, &key); ret != 0; ret = mar8Sprev(node, &key)) {
		printf("found 64-bit key: %" PRId64 "\n", (int64_t)key);
	}
	printf("\n");
}

static void test2_mar8Uprint(void* node) {
	if (!node)
		return;

	uint64_t key = -1;
	int ret;
	for (ret = mar8Ulast(node, &key); ret != 0; ret = mar8Uprev(node, &key)) {
		printf("found 64-bit key: %" PRIu64 "\n", (uint64_t)key);
	}
	printf("\n");
}

static void test2_mar4Sprint(void* node) {
	if (!node)
		return;

	int32_t key = -1;
	int ret;
	for (ret = mar4Slast(node, &key); ret != 0; ret = mar4Sprev(node, &key)) {
		printf("found 32-bit key: %" PRId32 "\n", (int32_t)key);
	}
	printf("\n");
}

static void test2_mar4Uprint(void* node) {
	if (!node)
		return;

	uint32_t key = -1;
	int ret;
	for (ret = mar4Ulast(node, &key); ret != 0; ret = mar4Uprev(node, &key)) {
		printf("found 32-bit key: %" PRIu32 "\n", (uint32_t)key);
	}
	printf("\n");
}

static void test_sanity(void* node) {
	if (!node)
		return;

	int64_t key = 0;
	int ret;
	size_t count = 0;
	for (ret = mar8Sfirst(node, &key); ret != 0; ret = mar8Snext(node, &key)) {
		assert(mar8Stest(node, key));
		++count;
	}
	key = (int64_t)-1;
	assert(!mar8Snext(node, &key));
	assert(count == mar8Ssize(node));
}

#if 0

int main(int argc, char **argv) {
	marika_error_t err;

	void* marika = NULL;
	static const int32_t keys[] = {
		  0,  -10,  20,  -30,  40,
		  10,  -110,  120,  -130,  140,
		  110,  -1110,  1120,  -1130,  1140,
		  210,  -2110,  2120,  -2130,  2140,
	};

	for (unsigned i = 0; i < sizeof(keys)/sizeof(keys[0]); ++i) {
		if (!mar4Sset(&marika, keys[i], &err)) {
			if (err.errno) {
				fprintf(stderr, "errno: %u\n", (unsigned)err.errno);
				exit(1);
			}
		}
	}

	test1_mar4Sprint(marika);
	test2_mar4Sprint(marika);
	mar4Sprint(stdout, marika);

	printf("memused: %zu\n", mar4Smemused(marika));

	int32_t found = 89;
	int ret = mar4Slast(marika, &found);
	printf("ret: %d\n", ret);
	printf("found: %" PRIu32 "\n", found);
	printf("items between 50 110: %zd\n", mar4Scount(marika, 50, 110));
	printf("items between 50 110: %zd\n", mar4Scount(marika, 110, 50));

	marika_iterator_t it;
	mar4Sprint(stdout, marika);
	mar4Siterator_init(marika, &it);
	int32_t index;
	printf("iteration\n");
	while (mar4Siterate(&it, &index)) {
		printf("   %" PRId32 "\n", index);
	}
	printf("iteration done\n");

	mar4Siterator_destroy(&it);
	mar4Sfree(&marika);
}

#elif 1

int main(int argc, char **argv) {
	marika_error_t err;

	void* marika = NULL;
	static const int64_t keys[] = {
		  0,    -10,   -20,  -30,  -40,  -50,  -60,  -70,  -80,  -90,
		  -100, -110, -120, -130, -140, -150, -160, -170, -180, -190,
		  -200, -210, -220, -230, -240, -250, -260, -270, -280, -290,
		  -300, -310, -255, -33, -34, -35, -36, -37, -38, -39,
		  -101, -111, -121, -131, -141, -151, -161, -171, -181, -191,
		  -102, -112, -122, -132, -142, -152, -162, -172, -182, -192,
		  -103, -113, -123, -133, -143, -153, -163, -173, -183, -193,
		  -104, -114, -124, -134, -144, -154, -164, -174, -184, -194,
		  -105, -115, -125, -135, -145, -155, -165, -175, -185, -195,
		  -106, -116, -126, -136, -146, -156, -166, -176, -186, -196,
		  -106, -116, -126, -136, -146, -156, -166, -176, -186, -196,
	};

	for (unsigned i = 0; i < sizeof(keys)/sizeof(keys[0]); ++i) {
		if (!mar8Sset(&marika, keys[i], &err)) {
			if (err.errno) {
				fprintf(stderr, "errno: %u\n", (unsigned)err.errno);
				exit(1);
			}
		}
	}

	test1_mar8Sprint(marika);
	test2_mar8Sprint(marika);
	mar8Sprint(stdout, marika);

	printf("memused: %zu\n", mar8Smemused(marika));

	int64_t found = 89;
	int ret = mar8Slast(marika, &found);
	printf("ret: %d\n", ret);
	printf("found: %" PRId64 "\n", (int64_t)found);
	printf("items between 50 110: %zd\n", mar8Scount(marika, 50, 110));
	printf("items between 50 110: %zd\n", mar8Scount(marika, 110, 50));

	mar8Sfree(&marika);
}

#else

int main(int argc, char **argv) {
	marika_error_t err;

	void* marika = NULL;
	int new_item;

	int64_t key;
	int32_t* pvalue;
	#define FMT_KEY PRId64
	#define FMT_VALUE PRId32

	for (int k = -1100; k <= 1900; k += 100) {
		pvalue = mar8S4Sput(&marika, k, &new_item, &err);
		printf("new_item=%d\n", new_item);
		printf("value=%" FMT_VALUE "\n", *pvalue);
		*pvalue = 1000 + k;

		pvalue = mar8S4Sput(&marika, k, &new_item, &err);
		printf("new_item=%d\n", new_item);
		printf("value=%" FMT_VALUE "\n", *pvalue);

		printf("\n");
	}
	for (int k = -5100; k <= 5900; k += 100) {
		pvalue = mar8S4Sput(&marika, k, &new_item, &err);
		printf("new_item=%d\n", new_item);
		printf("value=%" FMT_VALUE "\n", *pvalue);
		*pvalue = 1000 + k;

		pvalue = mar8S4Sins(&marika, k, &err);
		pvalue = mar8S4Sput(&marika, k, &new_item, &err);
		printf("new_item=%d\n", new_item);
		printf("value=%" FMT_VALUE "\n", *pvalue);

		printf("\n");
	}

	printf("keys: %zd\n", mar8S4Ssize(marika));
	printf("memused: %zd\n", mar8S4Smemused(marika));
	printf("count(0, -1): %zd\n", mar8S4Scount(marika, 0, -1));
	printf("count(500, 1300): %zd\n", mar8S4Scount(marika, 500, 1300));
//	mar8S4Sprint(stdout, marika);
	printf("sanity check: %d\n", mar8S4Ssanity(marika, &err));

	for (pvalue = mar8S4Sfirst(marika, &key); pvalue != 0; pvalue = mar8S4Snext(marika, &key)) {
		printf("%" FMT_KEY " -> %" FMT_VALUE "\n", key, *pvalue);
	}
	key = -1;
	for (pvalue = mar8S4Slast(marika, &key); pvalue != 0; pvalue = mar8S4Sprev(marika, &key)) {
		printf("%" FMT_KEY " -> %" FMT_VALUE "\n", key, *pvalue);
	}
	for (key = 100; key <= 1590; key += 50) {
		pvalue = mar8S4Sget(marika, key);
		printf("key %" FMT_KEY " -> value=%p\n", key, pvalue);
	}
	printf("\n");

	printf("iteration\n");
	marika_iterator_t it;
	mar8S4Siterator_init(marika, &it);
	while (pvalue = mar8S4Siterate(&it, &key), pvalue != NULL) {
		printf("   %" FMT_KEY " -> %" FMT_VALUE "\n", key, *pvalue);
	}
	mar8S4Siterator_destroy(&it);
	printf("iteration done\n");

	mar8S4Sfree(&marika);
}

#endif
