#include<iostream>
using namespace std;

int find_element(int arr[], int n, int key) {

	int start = 0;
	int end = n - 1;

	while (start <= end) {

		int mid = (start + end) / 2;

		if (arr[mid] == key)
			return mid + 1;

		if (arr[start] <= arr[mid]) {

			// 2 cases : Element lies in the left or right of the mid

			if (arr[start] <= key and arr[mid] >= key) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}
		else if (arr[end] >= arr[mid]) {
			if (arr[mid] <= key and arr[end] >= key) {
				start = mid + 1;
			}
			else {
				end = mid - 1;
			}
		}
	}

	return -1;
}

int main() {

	int n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int key;
	cin >> key;

	cout << find_element(arr, n, key) << endl;

	return 0;
}