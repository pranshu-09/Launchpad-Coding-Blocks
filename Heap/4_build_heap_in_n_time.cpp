#include<iostream>
#include<vector>
using namespace std;

bool min_heap = false;

bool compare(int a, int b) {

	if (min_heap) {
		return a < b;
	}
	else {
		return a > b;
	}
}

void heapify(vector<int>&v, int idx) {

	int child1 = 2 * idx;
	int child2 = child1 + 1;

	int last = v.size() - 1;
	int min_idx = idx;

	if (child1 <= last and compare(v[child1], v[min_idx])) {
		min_idx = child1;
	}
	if (child2 <= last and compare(v[child2], v[min_idx])) {
		min_idx = child2;
	}

	if (min_idx != idx) {
		swap(v[min_idx], v[idx]);
		heapify(v, min_idx);
	}
}

void build_heap_optimised(vector<int>&v) {

	for (int i = (v.size() - 1 / 2); i >= 1; i--) {
		heapify(v, i);
	}
}

int main() {

	int n;
	cin >> n;

	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	build_heap_optimised(v);

	for (auto x : v) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}