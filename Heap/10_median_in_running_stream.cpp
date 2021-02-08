#include<iostream>
#include<queue>
using namespace std;

int main() {

	priority_queue<int> left_heap;
	priority_queue<int, vector<int>, greater<int> > right_heap;

	int d;
	cin >> d;

	left_heap.push(d);

	float median = d;

	cout << "Median -> " << median << endl;

	cin >> d;

	while (d != -1) {

		if (left_heap.size() > right_heap.size()) {

			if (d < median) {
				right_heap.push(left_heap.top());
				left_heap.pop();
				left_heap.push(d);
			}
			else {
				right_heap.push(d);
			}

			median = (left_heap.top() + right_heap.top()) / 2.0;

		}
		else if (right_heap.size() > left_heap.size()) {

			if (d > median) {
				left_heap.push(right_heap.top());
				right_heap.pop();
				right_heap.push(d);
			}
			else {
				left_heap.push(d);
			}

			median = (left_heap.top() + right_heap.top()) / 2.0;
		}
		else {

			if (d < median) {
				left_heap.push(d);
				median = left_heap.top();
			}
			else {
				right_heap.push(d);
				median = right_heap.top();
			}
		}

		cout << "Median -> " << median << endl;
		cin >> d;
	}

	return 0;
}