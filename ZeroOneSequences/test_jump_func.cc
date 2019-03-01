#include <iostream>
#include "linear_solution.cc"

int main() {
	uint total_q, ql, zl;
	std::cin >> total_q >> ql >> zl;
	std::cout << jumps_for_q(total_q, zl, ql);
}
