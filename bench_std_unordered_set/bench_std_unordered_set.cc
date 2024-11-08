#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cstdint>
#include <unordered_set>

typedef uint32_t mkey_t;

static const size_t COUNT = 58000000;

int main(int argc, char **argv) {
	std::unordered_set<mkey_t> key_set;
	mkey_t *keys = static_cast<mkey_t*>(calloc(COUNT, sizeof(mkey_t)));
	srand(100500);
	for (int i = 0; i < COUNT; ++i) {
		keys[i] = rand();
	}
	time_t before = time(NULL);
	for (int i = 0; i < COUNT; ++i) {
		key_set.insert(keys[i]);
	}
	free(keys);
	printf("time: %zu\n", size_t(time(NULL) - before));
	printf("total keys=%zu\n", key_set.size());

//	for (auto v: key_set) {
//		printf("v=%zu\n", v);
//	}
//	print_tree(top, 0);
}
