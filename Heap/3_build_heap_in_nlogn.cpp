#include<iostream>
#include<vector>
using namespace std;

void build_heap(vector<int> &v) {

	for (int i = 2; i < v.size(); i++) {

		int idx = i;
		int parent = idx / 2;

		while (idx > 1 and v[idx] > v[parent]) {
			swap(v[idx], v[parent]);
			idx = parent;
			parent = parent / 2;
		}
	}
}

void print(vector<int>v) {

	for (auto x : v) {
		cout << x << " ";
	}
	cout << endl;
}

int main()
{
	int n;
	cin >> n;

	vector<int> v;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	print(v);

	build_heap(v);

	print(v);

	return 0;
}