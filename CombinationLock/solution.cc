#include <iostream>
#include <cmath>

using namespace std;

#define RATIO (360 / 40)

int rotate_clockwise(int start, int stop) {
	if (start < stop) {
		return RATIO * (40 + start - stop);
	} else {
		return RATIO * (start - stop);
	}
}

int rotate_counter_clockwise(int start, int stop) {
	if (start > stop) {
		return RATIO * (40 + stop - start);
	} else {
		return RATIO * (stop - start);
	}
}

int main() {
	int init, fst, snd, thd;

	while (true) {
		cin >> init >> fst >> snd >> thd;
		if (init == 0 && fst == 0 && snd == 0 && thd == 0) {
			break;
		}

		int deg = 0;
		deg += 720;
		deg += rotate_clockwise(init, fst);
		deg += 360;
		deg += rotate_counter_clockwise(fst, snd);
		deg += rotate_clockwise(snd, thd);
		cout << deg << "\n";
	}
}
