#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <marika.h>

#include <mkc_macro.h>

static const int keys[] = {
	2024,  2023,  2020,  1999,  1992,
};

static char const * const values[] = {
	"libmarika",  "libnina",  "libnata",  "libJudy",  "std::map",
};

int main(int argc, char **argv) {
	marika_error_t err;
	marika_iterator_t iterator;
	void* map = NULL; // empty map
	int key;
	void** pvalue;

	// inserting
	for (size_t i = 0; i < sizeof(keys)/sizeof(keys[0]); ++i) {
		pvalue = marIPins(&map, keys[i], &err);
		assert(pvalue);
		*pvalue = __UNCONST(values[i]);
	}

	// iteration
	printf("inserted keys:\n");
	marIPiterator_init(map, &iterator);
	while (pvalue = marIPiterate(&iterator, &key), pvalue != NULL) {
		printf("   %d -> %s\n", key, (char *) *pvalue);
	}
	marIPiterator_destroy(&iterator);
	printf("\n");

	// check for keys
	for (key = -2000; key <= 2000; ++key) {
		if (pvalue = marIPget(map, key), pvalue != NULL)
			printf("map[%d] == %s\n", key, (char*) *pvalue);
	}
	printf("\n");

	// memory must be freed
	marIPfree(&map);
	assert(map == NULL);

	return 0;
}
