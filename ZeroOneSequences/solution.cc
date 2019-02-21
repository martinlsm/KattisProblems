#include <string>
#include <iostream>

using std::string;
using uint = unsigned int;

void swap(uint from, uint to, string& seq) {
	while (to < from) {
		char temp = seq[from];
		seq[from] = seq[from - 1];
		seq[from - 1] = temp;
		from--;
	}
}

uint nbr_swaps(uint i, uint ones_start, uint current_cost, string& seq) {
	uint sum = current_cost;
	while (i < seq.size()) {
		if (seq[i] == '0') {
			if (ones_start < i) {
				sum += i - ones_start;
				swap(ones_start, i, seq);
			}
			ones_start++;
		} else if (seq[i] == '?') {
			string s0 = seq;
			s0[i] = '0';
			string s1 = seq;
			s1[i] = '1';
			return nbr_swaps(i, ones_start, sum, s0)
			     + nbr_swaps(i, ones_start, sum, s1);
		}
	i++;
	}
	return sum;
}

uint nbr_swaps(string seq) {
	return nbr_swaps(0, 0, 0, seq) % 1000000007;
}

int main() {
	string input;
	std::cin >> input;
	std::cout << nbr_swaps(input) << std::endl;
}

