#include<iostream>
using namespace std;

int binary_search(int arr[], int n, int key) {

	int start = 0;
	int end = n - 1;

	while (start < end) {
		int mid = (end + start) / 2;

		if (arr[mid] == key)
			return mid + 1;
		else if (arr[mid] > key) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
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

	cout << binary_search(arr, n, key);


}