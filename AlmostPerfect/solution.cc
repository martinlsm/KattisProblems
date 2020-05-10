#include <bits/stdc++.h>

using namespace std;

long long sum_of_divisors(long long number) {
	long long sum = 1;
	for (long long i = 2; i <= sqrt(number); i++) {
		if (number % i == 0) {
			sum += number / i;
			if (number / i != i)
				sum += i;

		}
	}
	return sum;
}

int main()
{
	long long number;
	while (scanf("%lld", &number) == 1) {
		long long sum = sum_of_divisors(number);
		if (sum == number) {
			cout << number << " perfect\n";
		} else if (std::abs(sum - number) <= 2) {
			cout << number << " almost perfect\n";
		} else {
			cout << number << " not perfect\n";
		}
	}
}


