#include<iostream>
#include<algorithm>
using namespace std;

#define int long long

bool can_place_cow(int stalls[], int n, int c, int min_sep) {

	int cows_count = 1;
	int curr_cow = stalls[0];

	for (int i = 1; i < n; i++) {
		if (stalls[i] - curr_cow >= min_sep) {
			curr_cow = stalls[i];
			cows_count++;

			if (cows_count == c)
				return true;
		}
	}

	return false;
}

int32_t main() {

	int t;
	cin >> t;

	while (t--) {

		int n, c;
		cin >> n >> c;

		int stalls[n];
		for (int i = 0; i < n; i++)
			cin >> stalls[i];

		sort(stalls, stalls + n);

		int start = 0;
		int end = stalls[n - 1] - stalls[0];

		int ans = 0;

		while (start <= end) {

			int mid = (start + end) / 2;

			bool is_placable = can_place_cow(stalls, n, c, mid);
			if (is_placable) {
				ans = mid;
				start = mid + 1;
			}
			else {
				end = mid - 1;
			}
		}

		cout << ans << endl;
	}

}