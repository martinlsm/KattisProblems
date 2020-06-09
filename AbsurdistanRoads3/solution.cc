#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

void export_dot(ostream& os, unordered_map<int, vector<int>> edges) {
	os << "graph input_graph {\n";
	for (auto p : edges) {
		os << p.first << " -- { ";
		for (int n : p.second) {
			if (n > p.first)
				os << n << " ";
		}
		os << "}\n";
	}
	os << "}\n";
}

void print_edges(unordered_map<int, vector<int>> e) {
	for (auto p : e) {
		cout << p.first << " -> { ";
		for (int n : p.second) {
			cout << n << " ";
		}
		cout << "}\n";
	}
}

int main() {
	int N;
	cin >> N;
	vector<int> neighbour_count;
	for (int i = 0; i <= N; i++) neighbour_count.push_back(0);
	unordered_map<int, vector<int>> edges;
	for (int i = 0; i < N; i++) {
		int e1, e2;
		cin >> e1 >> e2;
		neighbour_count[e1]++;
		neighbour_count[e2]++;
		edges[e1].push_back(e2);
		edges[e2].push_back(e1);
		// Detect two vertex cycle here?
	}

	ofstream ofs;
	ofs.open("input.gv", std::ofstream::out);
	export_dot(ofs, edges);

	// print_edges(edges);
	vector<int> one_neighbour_vertices;
	for (int i = 1; i <= N; i++) {
		int n = neighbour_count[i];
		// cout << "neighbours(" << i << ") = " << n << "\n";
		if (n == 1) {
			one_neighbour_vertices.push_back(i);
		}
	}

	for (int v : one_neighbour_vertices) {
		// cout << "removing " << v << "\n";
		while (edges[v].size() == 1) {
			int neighbour = edges[v][0];
			// cout << "  neighbour " << neighbour << "\n";
			edges[v] = {};
			edges[neighbour].erase(remove(edges[neighbour].begin(), edges[neighbour].end(), v),
									edges[neighbour].end());
			cout << v << " " << neighbour << "\n";
			v = neighbour;
		}
	}
	// print_edges(edges);

	// find a vertex in the cycle
	int v;
	int nodes_left = 0;
	for (auto p : edges) {
		int vv = p.first;
		vector<int> n = p.second;
		if (n.size() > 1) {
			nodes_left++;
			v = vv;
		}
	}

	if (nodes_left == 2) {
		int neighbour = edges[v][0];
		cout << v << " " << neighbour << "\n";
		cout << neighbour << " " << v << "\n";
		return 0;
	}

	// cout << "start in cycle " << v << "\n";

	int neighbour = edges[v][0];
	// cout << "  neighbour " << neighbour << "\n";
	edges[v] = { edges[v][1] };	
	edges[neighbour].erase(remove(edges[neighbour].begin(), edges[neighbour].end(), v),
							edges[neighbour].end());
	cout << v << " " << neighbour << "\n";
	v = neighbour;
	// print_edges(edges);
	while (edges[v].size() == 1) {
		// cout << "processing " << v << "\n";
		neighbour = edges[v][0];
		// cout << "  neighbour " << neighbour << "\n";
		edges[v] = {};	
		edges[neighbour].erase(remove(edges[neighbour].begin(), edges[neighbour].end(), v),
								edges[neighbour].end());
		// print_edges(edges);
		cout << v << " " << neighbour << "\n";
		v = neighbour;
	}
}
