#include <iostream>
#include <vector>

using namespace std;

int maximum_subarray(vector<int>& v) {
	int N = v.size();
	int max_sum = 0;
	int curr_sum = 0;
	for (int i = 0; i < N; i++) {
		curr_sum = max(0, curr_sum + v[i]);
		max_sum = max(curr_sum, max_sum);
	}
	return max_sum;
}

int main() {
	int N, P;
	vector<int> v;

	scanf("%d %d", &N, &P);
	for (int i = 0; i < N; i++) {
		int c;
		scanf("%d", &c);
		v.push_back(c - P);
	}

	int max_sum = maximum_subarray(v);
	cout << max_sum << "\n";
}
