#include "solution.h"
#include <vector>
#include <string>
#include <fstream>

using std::vector;
using std::string;

vector<string> test_names() {
	vector<string> file_names;
	std::ifstream ifs{"testlist"};
	string line;
	while (std::getline(ifs, line)) {
		file_names.push_back(line);
	}
	return file_names;
}

bool compare(const string& test) {
	std::ifstream efs{string{"test/" + test + ".expected"}};
	std::ifstream ofs{string{"test/" + test + ".out"}};
	string eline, oline;
	while (std::getline(efs, eline)) {
		if (std::getline(ofs, oline)) {
			if (oline != eline) {
				return false;
			}
		} else {
			return false;
		}
	}
	if (std::getline(ofs, oline)) {
		return false;
	}
	return true;
}

void produce_and_compare(const vector<string>& tests) {
	for (const string& t : tests) {
		std::cout << "Test: " << t << "\n";
		std::ifstream ifs{string{"test/" + t + ".in"}};
		std::ofstream ofs{string{"test/" + t + ".out"}};
		solve(ifs, ofs);
		bool compared = compare(t);
		if (compared) {
			std::cout << "  \033[1;32mPassed\033[0m\n";
		} else {
			std::cout << "  \033[1;31mWrong answer\033[0m\n";
		}
	}

}

int main() {
	vector<string> tests = test_names();
	produce_and_compare(tests);
}
