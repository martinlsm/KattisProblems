#include "solution.h"

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using std::string;
using std::vector;
using std::unordered_map;
using std::set;
using std::pair;

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

	auto itr = buy_order.begin();
	int current_shop = 0;
	int path = 1;
	set<pair<item, int>> path_nodes;
	size_t path_nodes_sz;

	while (itr != buy_order.end()) {
		path_nodes.insert(std::make_pair(*itr, current_shop));

		if (item_in_shops.find(*itr)->second.count(current_shop)) {
			++itr;
		} else {
			++current_shop;
		}

		if (current_shop == N) {
			path = 0;
			break;
		}
	}

	path_nodes_sz = path_nodes.size();

	if (path) {
		auto itr = buy_order.rbegin();
		current_shop = N - 1;
		while (current_shop >= 0) {
			auto previous = itr + 1;
			path_nodes.insert(std::make_pair(*itr, current_shop));
			if (previous != buy_order.rend() && item_in_shops.find(*previous)->second.count(current_shop)) {
				itr = previous;
			} else {
				--current_shop;
			}
		}
		if (path_nodes_sz != path_nodes.size()) {
			path = 2;
		}
	}

	if (path > 1) {
		os << "ambiguous";
	} else if (path == 1) {
		os << "unique";
	} else {
		os << "impossible";
	}
	os << std::endl;

	buy_order = {};
	item_in_shops = {};
}
