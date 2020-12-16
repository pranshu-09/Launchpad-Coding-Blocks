#include<iostream>
using namespace std;

bool can_make_p_paratas(int ranks[], int l, int p, int curr_time) {

	int pratas_made = 0;

	for (int i = 0; i < l; i++) {

		int val = curr_time;
		int prata = ranks[i];
		int count = 0;

		while (val > 0) {
			val = val - prata;

			if (val >= 0) {
				count++;
				prata += ranks[i];
			}
		}

		pratas_made += count;

		if (pratas_made >= p)
			return true;
	}

	return false;
}

int main() {

	int t;
	cin >> t;

	while (t--) {
		int p, l;
		cin >> p >> l;


		int min_rank = 9;

		int ranks[l];
		for (int i = 0; i < l; i++) {
			cin >> ranks[i];
			min_rank = min(min_rank, ranks[i]);
		}

		int max_time = 0;
		for (int i = 1; i <= p; i++) {
			max_time += (i * min_rank);
		}

		int min_time = 0;
		int ans = 0;

		while (min_time <= max_time) {

			int mid = (min_time + max_time) / 2;

			bool paratas_possible = can_make_p_paratas(ranks, l, p, mid);

			if (paratas_possible) {
				ans = mid;
				max_time = mid - 1;
			}
			else {
				min_time = mid + 1;
			}

		}

		cout << ans << endl;
	}

}