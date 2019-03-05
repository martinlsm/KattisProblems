#include <iostream>
#include <cmath>
#include <vector>

using std::string;
using std::vector;
using ulong = unsigned long;
using uint = unsigned int;

ulong MOD_WRAP = 1000000007;

void zeros_and_qs(uint v[2], const string& seq) {
	for (uint i = 0; i < seq.size(); i++) {
		if (seq[i] == '0') v[0] += 1;
		if (seq[i] == '?') v[1] += 1;
	}
}

ulong fac(uint n) {
	ulong product = 1;
	for (uint i = 2; i <= n; i++) {
		product *= i;
	}
	return product;
}

ulong binomial(uint n, uint k) {
	return fac(n) / (fac(n-k) * fac(k));
}

ulong jumps_for_one(uint total_q, uint zeros_left, uint qs_left) {
	ulong sum = 0;
	for (uint k = 1; k <= qs_left; k++) {
		sum = (sum + k * binomial(qs_left, k)) % MOD_WRAP;
	}
	sum = (sum * static_cast<ulong>(std::pow(2, total_q - qs_left))) % MOD_WRAP;
	sum = (sum + zeros_left * static_cast<ulong>(std::pow(2, total_q))) % MOD_WRAP;
	return sum;
}

ulong jumps_for_q(uint total_q, uint zeros_left, uint qs_left) {
	return jumps_for_one(total_q - 1, zeros_left, qs_left);
}

ulong nbr_swaps(const string& seq) {
	uint z_q[2]{0};
	zeros_and_qs(z_q, seq);
	uint ql = z_q[1];
	uint zl = z_q[0];
	ulong sumswaps = 0;
	uint total_q = ql;
	for (uint i = 0; i < seq.size() - 1; i++) {
		if (seq[i] == '1') {
			sumswaps = (sumswaps + jumps_for_one(total_q, zl, ql)) % MOD_WRAP;
		} else if (seq[i] == '?') {
			ql -= 1;
			sumswaps = (sumswaps + jumps_for_q(total_q, zl, ql)) % MOD_WRAP;
		} else {
			zl -= 1;
		}
	}
	return sumswaps % MOD_WRAP;
}


int main() {
	string input;
	std::cin >> input;
	std::cout << nbr_swaps(input) << std::endl;
}

