#include "solution.h"

using std::string;

void solve(std::istream& is, std::ostream& os) {
	string input;
	is >> input;

	string output;
	char c = 0;
	auto itr = input.begin();
	while (itr != input.end()) {
		if (c != *itr)
			output.push_back(*itr);
		c = *itr;
		++itr;
	}
	os << output << std::endl;
}
