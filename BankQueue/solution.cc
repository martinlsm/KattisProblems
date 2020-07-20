#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

vector<int>::iterator
argmin(vector<int>::iterator start, vector<int>::iterator end) {
	int min_val = INT_MAX;
	vector<int>::iterator min_idx;
	for (auto it = start; it < end; ++it) {
		if (*it < min_val) {
			min_val = *it;
			min_idx = it; 
		}

	}
	return min_idx;
}

int main() {
	int N, T;
	cin >> N >> T;
	vector<pair<int, int>> deposits;
	for (int n = 0; n < N; n++) {
		int c, t;
		cin >> c >> t;
		deposits.emplace_back(t, c);
	}
	sort(deposits.begin(), deposits.end());
	
	vector<int> optimal;
	for (int i = 0; i < T; i++) {
		optimal.push_back(0);
	}

	for (auto deposit : deposits) {
		auto it = argmin(optimal.begin(), optimal.begin() + deposit.first + 1);
		if (*it < deposit.second) {
			*it = deposit.second;
		}
	}

	int result = 0;
	for (int e : optimal) {
		result += e;
	}
	cout << result << "\n";
}
