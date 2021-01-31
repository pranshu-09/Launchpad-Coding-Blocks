#include<iostream>
using namespace std;

int no_of_bsts(int n) {

	if (n == 0  or n == 1) {
		return 1;
	}

	int count = 0;

	for (int i = 1; i <= n; i++) {

		int left = no_of_bsts(i - 1);
		int right = no_of_bsts(n - i);

		count = count + (left * right);
	}

	return count;
}

int no_of_bsts_dp(int n) {

	int dp[n + 1];
	dp[0] = dp[1] = 1;

	for (int i = 2; i <= n; i++) {

		int count = 0;

		for (int j = 1; j <= i; j++) {

			int left = dp[j - 1];
			int right = dp[i - j];

			count += (left * right);
		}

		dp[i] = count;
	}

	return dp[n];
}

int main() {

	int n;
	cin >> n;

	int ans = no_of_bsts_dp(n);
	cout << ans << endl;

	return 0;
}