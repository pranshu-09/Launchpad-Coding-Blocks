#include<iostream>
using namespace std;

#define ll long long

void prime_sieve(int prime[]) {

	// First Mark all odd numbers as prime -> Initialisation
	for (ll i = 3; i <= 1000000; i += 2) {
		prime[i] = 1;
	}

	for (ll i = 3; i <= 1000000; i += 2) {
		if (prime[i] == 1) {

			// Mark all multiples of i as not prime
			for (ll j = i * i; j <= 1000000; j += i) {
				prime[j] = i;
			}

		}
	}

	// Special Case
	prime[2] = 1;
	prime[0] = prime[1] = 0;
}

int main() {

	int prime[1000005] = {0};
	prime_sieve(prime);

	// Pre-computation
	int cum_sum[1000005] = {0};
	for (int i = 1; i <= 1000000; i++) {
		cum_sum[i] = cum_sum[i - 1] + prime[i];
	}

	int q;
	cin >> q;

	while (q--) {
		int a, b;
		cin >> a >> b;

		int no_of_prime = cum_sum[b] - cum_sum[a];

		cout << no_of_prime << endl;
	}

	return 0;
}