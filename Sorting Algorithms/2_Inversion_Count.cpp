#include<iostream>
using namespace std;

int merge(int arr[], int start, int end) {

	int mid = (start + end) / 2;

	int i = start, j = mid + 1, k = start;

	int temp[100];

	int count = 0;

	while (i <= mid and j <= end) {

		if (arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[j++];
			count += (mid - i + 1);
		}

	}

	while (i <= mid) {
		temp[k++] = arr[i++];
	}

	while (j <= end) {
		temp[k++] = arr[j++];
	}

	for (int l = start; l <= end; l++)
		arr[l] = temp[l];

	return count;
}

int inversion_count(int arr[], int start, int end) {

	if (start >= end) {
		return 0;
	}

	int mid = (start + end) / 2;

	int x = inversion_count(arr, start, mid);
	int y = inversion_count(arr, mid + 1, end);
	int z = merge(arr, start, end);


	return x + y + z;
}

int main() {

	int n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << inversion_count(arr, 0, n - 1) << endl;

	return 0;
}