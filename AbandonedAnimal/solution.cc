#include "solution.h"

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using std::string;
using std::vector;
using std::unordered_map;
using std::set;

typedef string item;

static vector<item> buy_order;
static unordered_map<item, set<int>> item_in_shops;
static int N, M;

static void parse_input(std::istream& is) {
	int K;
	is >> N;

	is >> K;
	for (int i = 0; i < K; ++i) {
		int store;
		item it;
		is >> store;
		is >> it;
		item_in_shops[it].emplace(store);
	}

	is >> M;
	for (int i = 0; i < M; ++i) {
		item it;
		is >> it;
		buy_order.push_back(it);
	}
}

void solve(std::istream& is, std::ostream& os) {
	parse_input(is);

	vector<vector<int>> paths_left;
	vector<vector<int>> integral_matrix;

	for (int i = 0; i < N; ++i) {
		paths_left.push_back({});
		integral_matrix.push_back({});
		for (int j = 0; j < M; ++j) {
			paths_left[i].push_back(0);
			integral_matrix[i].push_back(0);
		}
	}

	for (int i = N - 1; i >= 0; --i) {
		for (int j = 0; j < M; ++j) {
			item it = buy_order[j];
			bool has_item = item_in_shops[it].count(i);
			if (i < N - 1) {
				integral_matrix[i][j] = integral_matrix[i+1][j] + has_item;
			} else {
				integral_matrix[i][j] = has_item;
			}
		}
	}

	for (int i = N - 1; i >= 0; --i) {
		for (int j = M - 1; j >= 0; --j) {
			if (j < M - 1) {
				paths_left[i][j] = integral_matrix[i][j] + paths_left[i][j+1];
			} else {
				paths_left[i][j] = integral_matrix[i][j];
			}

		}
	}
	if (paths_left[0][0] > 1) {
		os << "ambiguous" << std::endl;
	} else if (paths_left[0][0] == 1) {
		os << "unique" << std::endl;
	} else {
		os << "impossible" << std::endl;
	}
	buy_order = {};
	item_in_shops = {};
}

/*
void solve(std::istream& is, std::ostream& os) {
	parse_input(is);

	auto itr = buy_order.begin();
	int current_shop = 0;
	int first_path = 1;
	int second_path = 1;

	while (itr != buy_order.end()) {
		if (item_in_shops.find(*itr)->second.count(current_shop)) {
			++itr;
		} else {
			++current_shop;
		}

		if (current_shop == N) {
			first_path = 0;
			break;
		}
	}

	os << (first_path == 1 ? "unique" : "impossible") << std::endl;

	buy_order = {};
	item_in_shops = {};
}
*/
