#include <iostream>
#include <algorithm>
#include <assert.h>

using namespace std;

bool isleftchild(int index) {
	assert(index > 0);
	return index % 2 == 1;
}

pair<int, int> get_fraction(int index) {
	if (index == 0) {
		return {1, 1};
	}

	pair<int, int> parent_frac = get_fraction((index - 1) / 2);
	int p = parent_frac.first;
	int q = parent_frac.second;
	if (isleftchild(index)) {
		return { p, p + q };
	} else { // right child
		return { p + q, q };
	}
}

bool isfracleftchild(pair<int, int> v) {
	assert(v.first != v.second);
	return v.first < v.second;
}

int get_index(pair<int, int> frac) {

}
