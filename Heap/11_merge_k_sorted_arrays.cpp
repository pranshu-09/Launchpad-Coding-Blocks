#include<iostream>
#include<queue>
#include<vector>

using namespace std;

typedef pair<int, pair<int, int> > custom_pair;

vector<int> merge_k_sorted_arrays(vector<vector<int> > arr) {

	vector<int> result;

	priority_queue<custom_pair, vector<custom_pair>, greater<custom_pair> > pq;

	for (int i = 0; i < arr.size(); i++) {
		pq.push({arr[i][0], {i, 0}});
	}

	while (!pq.empty()) {

		custom_pair p = pq.top();
		pq.pop();

		int elem = p.first;
		int x = p.second.first;
		int y = p.second.second;

		result.push_back(elem);

		if (y + 1 < arr[x].size()) {
			pq.push({arr[x][y + 1], {x, y + 1}});
		}
	}

	return result;
}

int main() {

	int n, k;
	cin >> n >> k;

	vector<vector<int> > arr;

	for (int i = 0; i < k; i++) {
		vector<int> v;

		for (int j = 0; j < n; j++) {

			int x;
			cin >> x;

			v.push_back(x);
		}

		arr.push_back(v);
	}

	vector<int> result = merge_k_sorted_arrays(arr);

	for (auto x : result) {
		cout << x << " ";
	}

	return 0;
}