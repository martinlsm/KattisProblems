#include <iostream>
#include <vector>

using namespace std;

static const vector<int> ref = {1, 1, 2, 2, 2, 8};

int main() {
	vector<int> v;
	int n;
	while (cin >> n) {
		v.push_back(n);
	}

	for (size_t i = 0; i < ref.size(); i++) {
		cout << (ref[i] - v[i]) << " ";
	}
	cout << "\n";
}
