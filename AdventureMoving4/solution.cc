#include <iostream>
#include <vector>

using namespace std;

int main() {
	// parse input
	int total_dist, last_pos, pos, cost;
	vector<pair<int, int>> stations;
	cin >> total_dist;
	last_pos = -100;  // because we start with 100 fuel
	while (cin >> pos >> cost) {
		if (pos - last_pos > 200) {
			cout << "Impossible\n";
			return 0;
		}
		stations.emplace_back(pos, cost);
		last_pos = pos;
	}
	if (total_dist - last_pos > 100) {
		cout << "Impossible\n";
		return 0;
	}
	stations.emplace_back(total_dist + 100, 0);


	int current_gas = 100;
	long long total_cost = 0;
	size_t i, j;
	i = 0;
	last_pos = 0;
	while (i < stations.size() - 1) {
		pos = stations[i].first;
		cost = stations[i].second;
		current_gas = current_gas - (pos - last_pos);

		bool fill_up = true;
		int min_cost = 1e7;
		j = i + 1;
		int opt_j;
		while (stations[j].first - pos <= 200) {
			if (stations[j].second < cost) {
				fill_up = false;
				opt_j = j;
				break;
			}
			if (stations[j].second <= min_cost) {
				min_cost = stations[j].second;
				opt_j = j;
			}
			j++;
		}

		int next_stop = stations[opt_j].first;
		int fill_amount = fill_up ? 200 - current_gas : max(0, next_stop - pos - current_gas);
		int gas_cost = fill_amount * cost;
		total_cost += gas_cost;
		current_gas += fill_amount;

		last_pos = pos;
		i = opt_j;
	}
	cout << total_cost << "\n";
}
