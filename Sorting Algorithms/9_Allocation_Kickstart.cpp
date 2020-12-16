#include<iostream>
#include <algorithm>
using namespace std;

int main() {

	int t;
	cin >> t;

	int l = 1;

	while (t--) {

		int n, b;
		cin >> n >> b;

		int arr[n];
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		sort(arr, arr + n);

		int ans = 0;

		for (int i = 0; i < n; i++) {

			if (b >= arr[i]) {
				ans++;
				b -= arr[i];
			}

		}

		cout << "Case #" << l++ << ": " << ans << endl;
	}

}