#include "solution.h"
#include <set>

using std::string;
using board = std::vector<unsigned int>;

unsigned int same_row_collisions(const board& b) {
    unsigned int sum = 0;
    std::multiset<unsigned int> set;
    for (unsigned int n : b) {
        if (set.count(n) > 0) {
            sum += set.count(n);
        }
        set.insert(n);
    }
    return sum;
}

unsigned int diagonal_collisions(const board& b) {
    unsigned int sum = 0;
    for (unsigned int q1_col = 0; q1_col < b.size(); q1_col++) {
        unsigned int q1_row = b[q1_col];
        for (unsigned int q2_col = q1_col + 1; q2_col < b.size(); q2_col++) {
            unsigned int q2_row = b[q2_col];
            int row_diff = static_cast<int>(q2_row) - static_cast<int>(q1_row);
            int col_diff = static_cast<int>(q2_col) - static_cast<int>(q1_col);
            if (col_diff == std::abs(row_diff)) {
                sum += 1;
            }
        }
    }
    return sum;
}

unsigned int num_collisions(const board& b) {
    unsigned int sum = 0;
    sum += same_row_collisions(b);
    sum += diagonal_collisions(b);
    return sum;
}

board parse_input(std::istream& is) {
	string line;
	board b;
	for (int i = 0; i < 8; i++) {
		std::getline(is, line);
		size_t pos = line.find("*");
		if (pos == string::npos) {
			throw string{"invalid"};
		}
		b.push_back(pos);
	}
	return b;
}

void solve(std::istream& is, std::ostream& os) {
	try {
		board b = parse_input(is);
		string output = num_collisions(b) == 0 ? "valid"  : "invalid";
		os << output << std::endl;
	} catch (string s) {
		os << s << std::endl;
		return;
	}
}
