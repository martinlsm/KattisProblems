#include <iostream>
#include <vector>

using namespace std;

long double area(vector<pair<int, int> > polygon) {
	int N = polygon.size();
	long double area(0);
	for (int i = 0; i < N - 1; i++) {
		int x0 = polygon[i].first;
		int y0 = polygon[i].second;
		int x1 = polygon[i + 1].first;
		int y1 = polygon[i + 1].second;
		area += x0 * y1;
		area -= y0 * x1;
	}
	int x0 = polygon[0].first;
	int xn = polygon[N - 1].first;
	int y0 = polygon[0].second;
	int yn = polygon[N - 1].second;
	area += xn * y0;
	area -= x0 * yn;
	return area / 2;
}

int main() {

	int corners;

	while (cin >> corners) {
		vector<pair<int, int>> polygon;
		if (corners == 0) {
			break;
		}
		for (int i = 0; i < corners; i++) {
			int x, y;
			cin >> x >> y;
			polygon.emplace_back(x, y);
		}
		double A = area(polygon);
		if (A < 0) {
			printf("CW %.1f\n", -A);
		} else {
			printf("CCW %.1f\n", A);
		}
	}
}
