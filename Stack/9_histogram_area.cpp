#include<iostream>
#include<stack>

using namespace std;

int max_histogram_area(int arr[], int n) {

	// Stack to store the indices of the bars
	stack<int> s;

	int max_area = 0;
	int i;

	for (i = 0; i < n;) {

		if (s.empty() or arr[s.top()] < arr[i]) {
			s.push(i);
			i++;
		}
		else {
			int top = s.top();
			s.pop();

			int area = 0;

			if (s.empty()) {
				area = arr[top] * (i);
			}
			else {
				area = arr[top] * (i - s.top() - 1);
			}

			if (max_area < area)
				max_area = area;
		}
	}

	while (!s.empty()) {
		int top = s.top();
		s.pop();

		int area = 0;

		if (s.empty()) {
			area = arr[top] * (i);
		}
		else {
			area = arr[top] * (i - s.top() - 1);
		}

		if (max_area < area)
			max_area = area;
	}

	return max_area;
}

int main() {

	int n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << max_histogram_area(arr, n);
}