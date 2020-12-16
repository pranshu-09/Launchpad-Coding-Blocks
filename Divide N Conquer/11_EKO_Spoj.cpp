#include<iostream>
using namespace std;

#define int long long
#define inf 1e18

bool can_trees_cut(int trees[], int n, int m, int mid) {

	int total_cut = 0;

	for (int i = 0; i < n; i++) {

		if (trees[i] > mid) {
			total_cut += (trees[i] - mid);
		}
	}

	if (total_cut >= m)
		return true;
	else
		return false;
}

int32_t main() {

	int n, m;
	cin >> n >> m;

	int max_height = -inf, min_height = inf;

	int trees[n];
	for (int i = 0; i < n; i++) {
		cin >> trees[i];
		max_height = max(max_height, trees[i]);
		min_height = min(min_height, trees[i]);
	}

	int ans = 0;

	while (min_height <= max_height) {

		int mid = (min_height + max_height) / 2;

		if (can_trees_cut(trees, n, m, mid)) {
			ans = mid;
			min_height = mid + 1;
		}
		else {
			max_height = mid - 1;
		}

	}

	cout << ans << endl;
}