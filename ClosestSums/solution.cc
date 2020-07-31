#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
	int n, m;
	int case_count = 0;

	while (cin >> n) {
		vector<int> nums;
		nums.reserve(n);
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			nums.push_back(num);
		}

		// insert padding
		nums.push_back(-10e8);
		nums.push_back(10e8);
		sort(nums.begin(), nums.end());

		cout << "Case " << ++case_count << ":\n";
		cin >> m;
		for (int i = 0; i < m; i++) {
			int query;
			cin >> query;

			int p1, p2;
			p2 = 2;
			while (2 * nums[p2] < query) {
				p2++;
			}
			p1 = p2 - 1;

			int closest = nums[p1] + nums[p2];
			while (true) {
				int n1 = nums[p1];
				int n2 = nums[p2];
				int n1_next = nums[p1 - 1];
				int n2_next = nums[p2 + 1];

				if (abs(n1 + n2 - query) < abs(closest - query)) {
					closest = n1 + n2;
				}

				if (abs(n1_next + n2 - query) < abs(n1 + n2_next - query)) {
					p1--;
					if (p1 == 0) break;
				} else {
					p2++;
					if ((size_t)p2 == nums.size() - 1) break;
				}
			}
			cout << "Closest sum to " << query << " is " << closest << ".\n";
		}
	}
}
