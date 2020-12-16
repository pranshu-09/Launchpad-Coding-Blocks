#include<iostream>
using namespace std;

#define ll long long

ll numbers_possible(ll n) {

	ll subsets = (1 << 8) - 1;
	ll ans = 0;

	ll prime[] = {2, 3, 5, 7, 11, 13, 17, 19};

	for (ll i = 1; i <= subsets; i++) {

		ll denom = 1ll;
		ll set_bits = __builtin_popcount(i);

		for (ll j = 0; j <= 7; j++) {

			if (i & (1 << j)) {
				denom = denom * prime[j];
			}

		}

		if (set_bits & 1) {
			ans += (n / denom);
		}
		else {
			ans -= (n / denom);
		}
	}

	return ans;
}

int main() {

	ll t;
	cin >> t;

	while (t--) {

		ll n;
		cin >> n;

		cout << numbers_possible(n) << endl;
	}

}