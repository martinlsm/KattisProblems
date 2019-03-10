#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using std::vector;
using std::string;

ulong MOD = 1000000007;
ulong INV_2 = 500000004;

vector<ulong> two_pows(ulong Q) {
	vector<ulong> p;
	ulong curr = 1;
	for (ulong i = 0; i <= Q; i++) {
		p.push_back(curr);
		curr = (curr * 2) % MOD;
	}
	return p;
}

vector<ulong> z1(const string& seq, ulong Q) { 
	vector<ulong> p = two_pows(Q);
	vector<ulong> zs;
	for (ulong i = 0; i <= seq.size(); i++)
		zs.push_back(0);
	for (long i = seq.size() - 1; i >= 0; --i) {
		if (seq[i] == '0') {
			zs[i] = (zs[i+1] + p[Q]) % MOD;
		} else if (seq[i] == '1') {
			zs[i] = zs[i+1];
		} else { // ?
			zs[i] = (zs[i+1] + p[Q-1]) % MOD;
		}
	}
	return zs;
}

ulong num_swaps(const string& seq) {
	ulong Q = std::count(seq.begin(), seq.end(), '?');
	vector<ulong> z = z1(seq, Q);
	ulong sum{0};
	for (ulong i = 0; i < seq.size(); i++) {
		if (seq[i] == '1') {
			sum = (sum + ((2 * z[i+1]) % MOD)) % MOD;	
		} else if (seq[i] == '?') {
			sum = (sum + z[i+1]) % MOD;
		}
	}
	return (sum * INV_2) % MOD;
}

/*
int main() {
	string input;
	std::cin >> input;
	std::cout << num_swaps(input) << std::endl;
}
*/
