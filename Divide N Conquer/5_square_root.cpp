#include<iostream>
using namespace std;

float square_root(int n) {
	int start = 0;
	int end = n;

	float ans = -1;

	while (start <= end) {
		int mid = (start + end) / 2;

		if (mid * mid == n) {
			return mid;
		}
		else if (mid * mid > n) {
			end = mid - 1;
		}

		else if (mid * mid < n) {
			ans = mid;
			start = mid + 1;
		}
	}


	// For float part of the square root

	float inc = 0.1;
	int p = 6;

	for (int i = 0; i < p; i++) {

		while (ans * ans <= n) {
			ans = ans + inc;
		}

		ans = ans - inc;
		inc = inc / 10;
	}

	return ans;
}

int main() {

	int n;
	cin >> n;

	cout << square_root(n) << endl;

	return 0;
}