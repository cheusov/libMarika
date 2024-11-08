#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <marika.h>

#include <mkc_macro.h>

static const KEY_TYPE keys[] = {
	0,  -10,  20,  -30,  40,
};

static char const * const values[] = {
	"libmarika",  "libnina",  "libnata",  "libJudy",  "std::map",
};

int main(int argc, char **argv) {
	marika_error_t err;
	marika_iterator_t iterator;
	void* map = NULL; // empty map
	KEY_TYPE key;
	void** pvalue;
	int ok;
	int new_item;

	// empty map
	printf("memory used by empty map: %zu bytes\n", FUNC_PREFPmemused(map));
	printf("keys in empty map: %zu\n", FUNC_PREFPsize(map));
	printf("\n");

	// inserting
	for (size_t i = 0; i < sizeof(keys)/sizeof(keys[0]); ++i) {
		key = keys[i];
		pvalue = FUNC_PREFPput(&map, key, &new_item, &err);
		if (!pvalue) {
			if (err.errno) {
				fprintf(stderr, "errno: %u\n", (unsigned)err.errno);
				exit(1);
			}
		}
		printf("%" FMT_KEY " is new item: %s\n", key, new_item ? "yes" : "no");
		printf("value for key %" FMT_KEY " is %p\n", key, *pvalue);

		*pvalue = __UNCONST(values[i]);
	}
	printf("\n");

	// memused
//	printf("memory used by map: %zu bytes\n", FUNC_PREFPmemused(map));
	printf("keys in map: %zu\n", FUNC_PREFPsize(map));
	printf("\n");

	// iteration #1
	printf("inserted keys:\n");
	FUNC_PREFPiterator_init(map, &iterator);
	while (pvalue = FUNC_PREFPiterate(&iterator, &key), pvalue != NULL) {
		printf("   %" FMT_KEY " -> %s\n", key, (char *) *pvalue);
	}
	FUNC_PREFPiterator_destroy(&iterator);
	printf("\n");

	// iteration #2
	printf("slow iteration [5,500] (smaller to larger order):\n");
	key = 5;
	for (pvalue = FUNC_PREFPfirst(map, &key); pvalue != 0 && key <= 500; pvalue = FUNC_PREFPnext(map, &key)) {
		printf("   %" FMT_KEY "\n", key);
	}
	printf("\n");

	// iteration #3
	printf("slow iteration (10,210) (larger to smaller order):\n");
	key = 210;
	for (pvalue = FUNC_PREFPprev(map, &key); pvalue != 0 && key > 10; pvalue = FUNC_PREFPprev(map, &key)) {
		printf("   %" FMT_KEY "\n", key);
	}
	printf("\n");

	// keys count within a region
	printf("keys in [10, 110]: %zd\n", FUNC_PREFPcount(map, 10, 110));
	printf("keys in [%" FMT_KEY ", 110]: %zd\n", (KEY_TYPE) -10, FUNC_PREFPcount(map, -10, 110));
	printf("\n");

	// check for keys
	for (key = -10; key <= 10; ++key) {
		if (FUNC_PREFPget(map, key))
			printf("key %" FMT_KEY " is in the map\n", key);
	}
	printf("\n");

	// internal structure of B+-Tree
//	printf("internal structure of B+-Tree (for learning ;-) ):\n");
//	FUNC_PREFPprint(stdout, map);
//	printf("\n");

	// memory must be freed
	FUNC_PREFPfree(&map);
	assert(map == NULL);

	// sanity check (for debugging and development)
	ok = FUNC_PREFPsanity(map, &err);
	if (ok) {
		fprintf(stderr, "Send a bug report to vle@gmx.net! :-/ errno: %u\n", (unsigned)err.errno);
		exit(1);
	}

	FUNC_PREFPfree(&map);

	return 0;
}
