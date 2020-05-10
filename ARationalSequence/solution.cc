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

bool is_frac_left_child(pair<int, int> v) {
	assert(v.first != v.second);
	return v.first < v.second;
}

int get_index(pair<int, int> frac) {
	int p = frac.first;
	int q = frac.second;
	if (p == 1 && q == 1) {
		return 0;
	}

	if (is_frac_left_child(frac)) {
		return 2 * get_index({p, q - p}) + 1;
	} else { // right child
		return 2 * get_index({p - q, q}) + 2;
	}
}

int F_inv(pair<int, int> frac) {
	return get_index(frac) + 1;
}

pair<int, int> F(int n) {
	return get_fraction(n - 1);
}

void print_frac(pair<int, int> frac) {
	cout << frac.first << "/" << frac.second;
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int K, p, q;
		string sfrac;
		cin >> K;
		cin >> sfrac;
		p = sfrac[0] - '0';
		q = sfrac[2] - '0';
		int index = F_inv({p, q});
		cout << "index = " << index << endl;
		pair<int, int> next_node = F(index + 1);
		cout << K << " ";
		print_frac(next_node);
		cout << "\n";
	}
}
