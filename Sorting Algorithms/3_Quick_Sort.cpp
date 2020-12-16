#include<iostream>
using namespace std;

int partition(int arr[], int start, int end) {

	int i = start - 1;
	int j;
	int pivot = arr[end];

	for (j = start; j <= end - 1; j++) {				// As arr[end] is the pivot element, loop till end-1

		if (arr[j] <= pivot) {
			i = i + 1;
			swap(arr[i], arr[j]);
		}

	}

	swap(arr[i + 1], arr[end]);		// Swapping pivot element and bringing it to its correct position

	return i + 1;			// The pivot element
}

void quick_sort(int arr[], int start, int end) {

	if (start >= end)
		return;

	int p = partition(arr, start, end);

	quick_sort(arr, start, p - 1);
	quick_sort(arr, p + 1, end);

}

int main() {

	int n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	quick_sort(arr, 0, n - 1);

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

}