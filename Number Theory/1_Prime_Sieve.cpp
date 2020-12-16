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
				prime[j] = 0;
			}

		}
	}

	// Special Case
	prime[2] = 1;
	prime[0] = prime[1] = 0;
}

int main() {

	int n;
	cin >> n;

	int prime[1000005] = {0};
	prime_sieve(prime);

	for (int i = 0; i <= n; i++) {
		if (prime[i] == 1) {
			cout << i << " ";
		}
	}

	cout << endl;

	return 0;
}