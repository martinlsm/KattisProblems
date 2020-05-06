#include <iostream>

using namespace std;

int main() {
	int n, T;

	cin >> n >> T;

	int i = 0;
	int total = 0;

	while (i < n) {
		int task;
		cin >> task;
		total += task;
		if (total > T) {
			break;
		}
		i++;
	}
	cout << i << "\n";
}
