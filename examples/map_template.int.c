#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <marika.h>

static const KEY_TYPE keys[] = {
	0,  -10,  20,  -30,  40,
	10,  -110,  120,  -130,  140,
	110,  -1110,  120,  -1130,  1140,
	210,  -2110,  2120,  -2130,  2140,
	10,  -110,  3120,  -3130,  3140,
};

int main(int argc, char **argv) {
	marika_error_t err;
	marika_iterator_t iterator;
	void* map = NULL; // empty map
	KEY_TYPE key;
	VALUE_TYPE* pvalue;
	int ok;
	int new_item;

	// empty map
	printf("memory used by empty map: %zu bytes\n", FUNC_PREFmemused(map));
	printf("keys in empty map: %zu\n", FUNC_PREFsize(map));
	printf("\n");

	// inserting
	for (size_t i = 0; i < sizeof(keys)/sizeof(keys[0]); ++i) {
		key = keys[i];
		pvalue = FUNC_PREFput(&map, key, &new_item, &err);
		if (!pvalue) {
			if (err.errno) {
				fprintf(stderr, "errno: %u\n", (unsigned)err.errno);
				exit(1);
			}
		}
		printf("%" FMT_KEY " is new item: %s\n", key, new_item ? "yes" : "no");
		printf("value for key %" FMT_KEY " is %" FMT_VALUE "\n", key, *pvalue);

		*pvalue = -(int64_t)(int32_t)key;
	}
	printf("\n");

	// memused
//	printf("memory used by map: %zu bytes\n", FUNC_PREFmemused(map));
	printf("keys in map: %zu\n", FUNC_PREFsize(map));
	printf("\n");

	// iteration #1
	printf("inserted keys:\n");
	FUNC_PREFiterator_init(map, &iterator);
	while (FUNC_PREFiterate(&iterator, &key)) {
		printf("   %" FMT_KEY "\n", key);
	}
	FUNC_PREFiterator_destroy(&iterator);
	printf("\n");

	// iteration #2
	printf("slow iteration [5,500] (smaller to larger order):\n");
	key = 5;
	for (pvalue = FUNC_PREFfirst(map, &key); pvalue != 0 && key <= 500; pvalue = FUNC_PREFnext(map, &key)) {
		printf("   %" FMT_KEY "\n", key);
	}
	printf("\n");

	// iteration #3
	printf("slow iteration (10,210) (larger to smaller order):\n");
	key = 210;
	for (pvalue = FUNC_PREFprev(map, &key); pvalue != 0 && key > 10; pvalue = FUNC_PREFprev(map, &key)) {
		printf("   %" FMT_KEY "\n", key);
	}
	printf("\n");

	// keys count within a region
	printf("keys in [10, 110]: %zd\n", FUNC_PREFcount(map, 10, 110));
	printf("keys in [%" FMT_KEY ", 110]: %zd\n", (KEY_TYPE) -10, FUNC_PREFcount(map, -10, 110));
	printf("\n");

	// check for keys
	for (key = -10; key <= 10; ++key) {
		if (FUNC_PREFget(map, key))
			printf("key %" FMT_KEY " is in the map\n", key);
	}
	printf("\n");

	// internal structure of B+-Tree
//	printf("internal structure of B+-Tree (for learning ;-) ):\n");
//	FUNC_PREFprint(stdout, map);
//	printf("\n");

	// memory must be freed
	FUNC_PREFfree(&map);
	assert(map == NULL);

	// sanity check (for debugging and development)
	ok = FUNC_PREFsanity(map, &err);
	if (ok) {
		fprintf(stderr, "Send a bug report to vle@gmx.net! :-/ errno: %u\n", (unsigned)err.errno);
		exit(1);
	}

	FUNC_PREFfree(&map);

	return 0;
}
