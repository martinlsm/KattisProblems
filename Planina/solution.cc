#include <iostream>

using namespace std;

long iter(int x) {
	long sidelen = 2;
	for (int i = 0; i < x; i++) {
		sidelen = 2 * sidelen - 1;
	}
	long ans = sidelen * sidelen;
	return ans;
}

int main() {
	int N;
	cin >> N;
	long ans = iter(N);
	cout << ans << "\n";
}
