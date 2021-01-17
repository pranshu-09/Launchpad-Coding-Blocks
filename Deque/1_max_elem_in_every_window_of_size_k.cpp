#include<iostream>
#include<deque>
#include<vector>
using namespace std;

vector<int> max_elem_of_k_window(int arr[], int n, int k) {

	// Deque to store index of maximum element
	deque<int> dq;
	vector<int> ans;

	int i;

	for (i = 0; i < k; i++) {
		while (!dq.empty() and arr[i] >= arr[dq.back()]) {
			dq.pop_back();
		}
		dq.push_back(i);
	}

	for (; i < n; i++) {

		ans.push_back(arr[dq.front()]);

		while (!dq.empty() and dq.front() <= i - k) {
			dq.pop_front();
		}

		while (!dq.empty() and arr[i] >= arr[dq.back()]) {
			dq.pop_back();
		}

		dq.push_back(i);
	}

	ans.push_back(arr[dq.front()]);

	return ans;
}

int main() {

	int n, k;
	cin >> n >> k;

	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	vector<int> ans = max_elem_of_k_window(arr, n, k);

	for (auto x : ans) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}