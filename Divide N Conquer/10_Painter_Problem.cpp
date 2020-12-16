#include<iostream>
using namespace std;

#define int long long

bool check_curr_time(int arr[], int n, int k, int mid) {

	int curr_time = arr[0];
	int curr_painter = 1;

	for (int i = 1; i < n; i++) {
		curr_time += arr[i];

		if (curr_time > mid) {
			curr_time = arr[i];
			curr_painter++;

			if (curr_painter > k)
				return false;
		}
	}

	return true;
}

int32_t main() {

	int n, k, t;
	cin >> n >> k >> t;

	int max_time = 0, min_time = 0;

	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		arr[i] *= t;

		max_time += arr[i];
		min_time = max(min_time, arr[i]);

	}

	int ans = 0;

	while (min_time <= max_time) {

		int mid = (min_time + max_time) / 2;

		if (check_curr_time(arr, n, k, mid)) {
			ans = mid;
			max_time = mid - 1;
		}
		else {
			min_time = mid + 1;
		}

	}

	cout << ans % 10000003 << endl;

}