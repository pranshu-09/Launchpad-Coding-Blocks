#include<iostream>
#include<vector>
using namespace std;

void heapify(vector<int>&arr, int n, int idx) {

	int child1 = 2 * idx;
	int child2 = 2 * idx + 1;

	int last = n - 1;
	int min_idx = idx;

	if (child1 <= last and arr[child1] > arr[min_idx]) {
		min_idx = child1;
	}
	if (child2 <= last and arr[child2] > arr[min_idx]) {
		min_idx = child2;
	}

	if (min_idx != idx) {
		swap(arr[idx], arr[min_idx]);
		heapify(arr, n, min_idx);
	}
}

void build_heap(vector<int>&arr) {

	for (int i = (arr.size() - 1) / 2; i >= 1; i--) {
		heapify(arr, arr.size(), i);
	}
}

void heap_sort(vector<int>&arr) {

	build_heap(arr);
	int n = arr.size();

	while (n > 1) {
		swap(arr[1], arr[n - 1]);
		n--;
		heapify(arr, n, 1);
	}

}

int main() {

	int n;
	cin >> n;

	vector<int> arr;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}

	heap_sort(arr);

	for (auto x : arr) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}