#include <iostream>
#include<queue>
using namespace std;

int main() {

	priority_queue<int> pq_max;										// To construct Maxheap
	priority_queue<int, vector<int>, greater<int> > pq_min;			// To construct Minheap


	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int no;
		cin >> no;
		pq_min.push(no);
		pq_max.push(no);
	}

	while (!pq_min.empty()) {
		cout << pq_min.top() << " ";
		pq_min.pop();
	}

	cout << endl;

	while (!pq_max.empty()) {
		cout << pq_max.top() << " ";
		pq_max.pop();
	}

	return 0;
}