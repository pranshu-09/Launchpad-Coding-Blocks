#include<iostream>
#include<vector>
using namespace std;

class Heap {

	vector<int> v;
	bool min_heap;

	bool compare(int a, int b) {
		if (min_heap) {					// For minheap, if idx value less than parent value, swap them
			return a < b;
		}
		else {
			return a > b;				// For maxheap, if idx value greater than parent value, swap them
		}
	}

	void heapify(int idx) {

		int child1 = 2 * idx;
		int child2 = child1 + 1;

		int last = v.size() - 1;
		int min_idx = idx;

		if (child1 <= last and compare(v[child1], v[idx])) {
			min_idx = child1;
		}
		if (child2 <= last and compare(v[child2], v[min_idx])) {
			min_idx = child2;
		}

		if (min_idx != idx) {
			swap(v[min_idx], v[idx]);
			heapify(min_idx);
		}
	}

public:

	Heap(int default_size = 10, bool type = true) {
		v.reserve(default_size);
		min_heap = type;
		v.push_back(-1);
	}

	void push(int d) {

		v.push_back(d);

		int idx = v.size() - 1;
		int parent = idx / 2;

		while (idx > 1 and compare(v[idx], v[parent])) {
			swap(v[idx], v[parent]);
			idx = parent;
			parent = parent / 2;
		}
	}


	void pop() {

		// 1. Swap first and last element
		int last = v.size() - 1;
		swap(v[1], v[last]);

		// 2. pop_back
		v.pop_back();

		// 3. Heapify
		heapify(1);
	}


	int top() {
		return v[1];
	}

	bool empty() {
		return v.size() == 1;
	}
};

int main() {

	Heap h;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		h.push(x);
	}

	while (!h.empty()) {
		cout << h.top() << " ";
		h.pop();
	}

	return 0;
}