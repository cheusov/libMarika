#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <marika.h>

static const ITEM_TYPE keys[] = {
	0,  -10,  20,  -30,  40,
	10,  -110,  120,  -130,  140,
	110,  -1110,  120,  -1130,  1140,
	210,  -2110,  2120,  -2130,  2140,
	10,  -110,  3120,  -3130,  3140,
};

int main(int argc, char **argv) {
	marika_error_t err;
	marika_iterator_t iterator;
	void* set = NULL; // empty set
	int ret;
	ITEM_TYPE item;

	memset(&err, 0, sizeof(err)); // err must be zeroed

	// empty set
	printf("memory used by empty set: %zu bytes\n", FUNC_PREFmemused(set));
	printf("items in empty set: %zu\n", FUNC_PREFsize(set));
	printf("\n");

	// inserting
	for (size_t i = 0; i < sizeof(keys)/sizeof(keys[0]); ++i) {
		item = keys[i];
		ret = FUNC_PREFset(&set, item, &err);
		if (!ret) {
			if (err.errno) {
				fprintf(stderr, "errno: %u\n", (unsigned)err.errno);
				exit(1);
			}
		}
		printf("%" FMT " is new item: %d\n", item, ret);
	}
	printf("\n");

//	FUNC_PREFprint(stdout, set);

	// memused
//	printf("memory used by set: %zu bytes\n", FUNC_PREFmemused(set));
	printf("items in set: %zu\n", FUNC_PREFsize(set));
	printf("\n");

	// iteration #1
	printf("inserted items:\n");
	FUNC_PREFiterator_init(set, &iterator);
	while (FUNC_PREFiterate(&iterator, &item)) {
		printf("   %" FMT "\n", item);
	}
	FUNC_PREFiterator_destroy(&iterator);
	printf("\n");

	// iteration #2
	printf("slow iteration [5,500] (smaller to larger order):\n");
	item = 5;
	for (ret = FUNC_PREFfirst(set, &item); ret != 0 && item <= 500; ret = FUNC_PREFnext(set, &item)) {
		printf("   %" FMT "\n", item);
	}
	printf("\n");

	// iteration #3
	printf("slow iteration (10,210) (larger to smaller order):\n");
	item = 210;
	for (ret = FUNC_PREFprev(set, &item); ret != 0 && item > 10; ret = FUNC_PREFprev(set, &item)) {
		printf("   %" FMT "\n", item);
	}
	printf("\n");

	// items count within a region
	printf("items in [10, 110]: %zd\n", FUNC_PREFcount(set, 10, 110));
	printf("items in [%" FMT ", 110]: %zd\n", (ITEM_TYPE) -10, FUNC_PREFcount(set, (ITEM_TYPE)-10, 110));
	printf("\n");

	// check for items
	for (item = -10; item <= 10; ++item) {
		if (FUNC_PREFtest(set, item))
			printf("item %" FMT " is in the set\n", item);
	}
	printf("\n");

	// internal structure of B+-Tree
//	printf("internal structure of B+-Tree (for learning ;-) ):\n");
//	FUNC_PREFprint(stdout, set);
//	printf("\n");

	// memory must be freed
	FUNC_PREFfree(&set);
	assert(set == NULL);

	// sanity check (for debugging and development)
	ret = FUNC_PREFsanity(set, &err);
	if (ret) {
		fprintf(stderr, "Send a bug report to vle@gmx.net! :-/ errno: %u\n", (unsigned)err.errno);
		exit(1);
	}

	FUNC_PREFfree(&set);

	return 0;
}
