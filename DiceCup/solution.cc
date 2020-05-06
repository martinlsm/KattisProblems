#include <iostream>

using namespace std;

int main() {
	int x, y;

	cin >> x >> y;

	if (x > y) {
		int temp = x;
		x = y;
		y = temp;
	}

	int max_count = y - x + 1;
	int max_start = x + 1;

	for (int i = 0; i < max_count; i++) {
		cout << max_start + i << "\n";
	}
}
