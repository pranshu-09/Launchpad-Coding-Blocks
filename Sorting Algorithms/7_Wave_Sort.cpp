#include<iostream>
using namespace std;

void wave_sort(int arr[], int n) {

	for (int i = 0; i < n; i += 2) {

		if (i != 0 and arr[i] < arr[i - 1]) {
			swap(arr[i], arr[i - 1]);
		}

		if (i != n - 1 and arr[i] < arr[i + 1]) {
			swap(arr[i], arr[i + 1]);
		}

	}

}

int main() {

	int n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	wave_sort(arr, n);

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

}