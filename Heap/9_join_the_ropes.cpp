#include<iostream>
#include<queue>
using namespace std;

int join_ropes(int ropes[], int n) {

	priority_queue<int, vector<int>, greater<int> > pq(ropes, ropes + n);

	int cost = 0;

	while (pq.size() > 1) {

		int a = pq.top();
		pq.pop();

		int b = pq.top();
		pq.pop();

		int new_rope = a + b;

		cost += new_rope;

		pq.push(new_rope);
	}

	return cost;
}

int main() {

	int n;
	cin >> n;

	int ropes[n];
	for (int i = 0; i < n; i++)
		cin >> ropes[i];

	cout << join_ropes(ropes, n) << endl;

	return 0;
}