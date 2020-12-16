#include<iostream>
using namespace std;

#define int long long

bool can_give_scholarship(int n, int m, int x, int y, int mid) {


	int req_coupons = mid * x;
	int available_coupons = m + (n - mid) * y;

	if (req_coupons <= available_coupons)
		return true;
	else
		return false;
}

int32_t main() {

	int n, m, x, y;
	cin >> n >> m >> x >> y;

	int start = 0;
	int end = n;

	int ans = 0;

	while (start <= end) {
		int mid = (start + end) / 2;

		if (can_give_scholarship(n, m, x, y, mid)) {
			ans = mid;
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}

	cout << ans << endl;

	return 0;
}