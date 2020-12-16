#include<iostream>
using namespace std;

bool max_read_possible(int books[], int n, int m, int min_read) {

	int curr_page = books[0];
	int curr_stu = 1;

	for (int i = 1; i < n; i++) {
		curr_page += books[i];

		if (curr_page > min_read) {
			curr_page = books[i];
			curr_stu++;

			if (curr_stu > m)
				return false;
		}
	}

	return true;
}

int main() {

	int t;
	cin >> t;

	while (t--) {

		int n, m;
		cin >> n >> m;

		int books[n];
		int max_read = 0, min_read = 0;

		for (int i = 0; i < n; i++) {
			cin >> books[i];
			max_read += books[i];
			min_read = max(min_read, books[i]);
		}

		int ans = 0;

		while (min_read <= max_read) {

			int mid = (min_read + max_read) / 2;

			bool is_possible = max_read_possible(books, n, m, mid);

			if (is_possible) {
				ans = mid;
				max_read = mid - 1;
			}
			else {
				min_read = mid + 1;
			}

		}
		cout << ans << endl;

	}

}