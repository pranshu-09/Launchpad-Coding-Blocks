#include<iostream>
using namespace std;

void merge(int arr[], int start, int end) {

	int mid = (start + end) / 2;

	int i = start, j = mid + 1, k = start;

	// Sort the array in a temporary array
	int temp[100];

	while (i <= mid and j <= end) {

		if (arr[i] > arr[j]) {
			temp[k++] = arr[j++];
		}
		else {
			temp[k++] = arr[i++];
		}

	}

	while (i <= mid) {
		temp[k++] = arr[i++];
	}

	while (j <= end) {
		temp[k++] = arr[j++];
	}


	// Copy the sorted temp array back to initial array
	for (int l = start; l <= end; l++) {
		arr[l] = temp[l];
	}

}

void merge_sort(int arr[], int start, int end) {

	// Base Case -> We don't need to do anything when there is only 1 element or no element
	if (start >= end) {
		return;
	}

	// Follow 3 steps;

	// 1. Divide the array
	int mid = (start + end) / 2;


	// 2. Recursively sort the 2 arrays
	merge_sort(arr, start, mid);
	merge_sort(arr, mid + 1, end);


	// 3. Merge the two Parts
	merge(arr, start, end);
}

int main() {

	int n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	merge_sort(arr, 0, n - 1);

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	cout << endl;

	return 0;
}