#include <iostream>

using namespace std;

int main() {
	long N;
	while (cin >> N) {
		int turns = 0;
		while (N > 1) {
			if (turns % 2 == 0) {
				N = (N + 8) / 9;
			} else {
				N = (N + 1) / 2;
			}
			++turns;
		}
		if (turns % 2 == 0) {
			cout << "Ollie wins.\n";
		} else {
			cout << "Stan wins.\n";
		}
	}
}
