#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

long double height(int n) {
	return std::pow(2.0L, (1 - 2 * n) / 4.0L);
}

pair<bool, long double> tape_amount(vector<long long> papers, int A_smallest) {
	long double tape = 0;
	int i = 2;
	long long need = 2;
	while (need > 0 && i <= A_smallest) {
		long long have = papers[i];
		tape += need / 2 * height(i);
		need = need - have;
		need *= 2;
		i++;
	}
	if (need > 0 && i > A_smallest) {
		return {false, -1};
	}
	return {true, tape};
}

int main() {
	cout.precision(17);
	int n;
	vector<long long> papers;
	papers.push_back(0);
	papers.push_back(0);
	cin >> n;
	for (int i = 2; i <= n; i++) {
		long long An;
		cin >> An;
		papers.push_back(An);
	}

	auto p = tape_amount(papers, n);
	
	if (!p.first) {
		cout << "impossible\n";
	} else {
		cout << p.second << "\n";
	}
}
