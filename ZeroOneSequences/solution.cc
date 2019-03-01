#include <string>
#include <iostream>

using std::string;
using uint = unsigned int;
using ulong = unsigned long;

ulong nbr_swaps(const string*);
ulong f(uint, uint, ulong, const string*);
ulong f0(uint, uint, ulong, const string*);

ulong nbr_swaps(const string* seq) {
	return f(0, 0, 0, seq) % 1000000007;
}

ulong f(uint i, uint ones_start, ulong current_cost, const string* seq) {
	while (i < seq->size()) {
		if ((*seq)[i] == '0') {
			current_cost += i - ones_start;
			ones_start++;
		} else if ((*seq)[i] == '?') {
			return f0(i, ones_start, current_cost, seq) + // Assuming seq[i] == 0
			       f(i+1, ones_start, current_cost, seq); // Assuming seq[i] == 1
		}
		i++;
	}
	return current_cost;
}

ulong f0(uint i, uint ones_start, ulong current_cost, const string* seq) {
	current_cost += i - ones_start;
	ones_start++;
	return f(i+1, ones_start, current_cost, seq);
}


int main() {
	string input;
	std::cin >> input;
	std::cout << nbr_swaps(&input) << std::endl;
}
