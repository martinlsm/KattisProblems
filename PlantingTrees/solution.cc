#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> v;

	for (int i = 0; i < N; ++i) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < N; ++i) {
		v[i] -= i;
	}


	long res = 1 + *max_element(v.begin(), v.end()) + v.size();

	cout << res << endl;
}
