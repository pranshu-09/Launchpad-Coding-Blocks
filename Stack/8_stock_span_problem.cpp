#include<iostream>
#include<stack>
#include<vector>

using namespace std;

vector<int> stock_span_problem(int arr[], int n) {

	stack<pair<int, int> > s;
	vector<int> span_array;

	s.push(make_pair(0, arr[0]));
	span_array.push_back(0);

	for (int i = 1; i < n; i++) {

		while (!s.empty() and s.top().second < arr[i]) {
			s.pop();
		}

		int max_idx = s.top().first;
		int span = i - max_idx;

		s.push(make_pair(i, arr[i]));
		span_array.push_back(span);
	}

	return span_array;
}

int main() {

	int n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	vector<int> res = stock_span_problem(arr, n);

	for (int i = 0; i < n; i++) {
		cout << res[i] << " ";
	}

}