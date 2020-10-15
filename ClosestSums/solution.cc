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
		sort(nums.begin(), nums.end());

		cout << "Case " << ++case_count << ":\n";
		cin >> m;
		for (int i = 0; i < m; i++) {
			int query;
			cin >> query;

			int p1, p2;
			p2 = 1;
			while ((size_t)p2 < nums.size() - 1 && 2 * nums[p2] < query) {
				p2++;
			}
			p1 = p2 - 1;

			int closest = nums[p1] + nums[p2];
			while (true) {
				int n1 = nums[p1];
				int n2 = nums[p2];

				if (abs(n1 + n2 - query) < abs(closest - query)) {
					closest = n1 + n2;
				}

				bool change = false;
				if (n1 + n2 > query) {
					change = true;
					p1--;
					if (p1 == -1) break;
				} else if (n1 + n2 < query) {
					change = true;
					p2++;
					if ((size_t)p2 == nums.size()) break;
				}

				if (!change) break;
			}
			cout << "Closest sum to " << query << " is " << closest << ".\n";
		}
	}
}
