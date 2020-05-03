#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> nums;
	nums.reserve(N);
	int x;
	for (int i = 0; i < N; ++i) {
		cin >> x;
		nums.emplace_back(x);
	}

	sort(nums.begin(), nums.end());

	for (int i = 0; i < N; ++i) {
		x = nums[i];
		cout << x;
		int y = x;
		while (i + 1 < N && nums[i] + 1 == nums[i + 1]) {
			++i;
			y = nums[i];
		}

		if (x + 2 <= y) {
			cout << "-" << y;
		} else if (x + 1 == y) {
			cout << " " << y;
		}

		if (i < N - 1) {
			cout << " ";
		}

	}

	cout << "\n";
}
