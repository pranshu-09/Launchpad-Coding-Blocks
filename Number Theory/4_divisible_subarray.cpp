#include<bits/stdc++.h>
using namespace std;

int pre[1000005], arr[1000005];

int main() {

	int t;
	cin >> t;

	while (t--) {

		int n;
		cin >> n;

		memset(pre, 0, sizeof(pre));

		pre[0] = 1; 		// Case when we are taking the null subarray. The sum of that subarray will be 0
		int sum = 0;

		for (int i = 0; i < n; i++) {

			cin >> arr[i];

			sum += arr[i];
			sum %= n;
			sum = (sum + n) % n;
			pre[sum]++;

		}

		long long int ans = 0;

		for (int i = 0; i < n; i++) {

			ans += (pre[i] * (pre[i] - 1) ) / 2;
		}

		cout << ans << endl;

	}

}