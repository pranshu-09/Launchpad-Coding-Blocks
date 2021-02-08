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

};


int main() {

	Heap h;

	int d;
	cin >> d;

	while (d != -1) {
		h.push(d);
		cin >> d;
	}

	return 0;
}