#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
	int N;
	vector<int> books;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int e;
		cin >> e;
		books.push_back(e);
	}

	sort(books.rbegin(), books.rend());

	int totalcost = 0;
	for (int i = 2; i < N; i += 3) {
		totalcost += books[i-2] + books[i-1];
	}
	
	for (int i = N - (N % 3); i < N; i++) {
		totalcost += books[i];
	}

	cout << totalcost << endl;
}
