#include <iostream>

using namespace std;

int main() {
	int X, Y, N;

	cin >> X >> Y >> N;

	for (int i = 1; i <= N; i++) {
		string s;
		if (i % X == 0) {
			s.append("Fizz");
		}
		if (i % Y == 0) {
			s.append("Buzz");
		}
		if (s == "") {
			s = std::to_string(i);
		}
		cout << s << "\n";
	}
}
