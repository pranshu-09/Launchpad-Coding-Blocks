#include<iostream>
using namespace std;

void counting_sort(int arr[], int n) {

	int largest = -1;

	for (int i = 0; i < n; i++) {
		largest = max(largest, arr[i]);
	}

	int *count = new int[largest + 1] {0};

	for (int i = 0; i < n; i++) {
		count[arr[i]]++;
	}

	int j = 0;
	for (int i = 0; i <= largest; i++) {
		while (count[i] > 0) {
			arr[j] = i;
			count[i]--;
			j++;
		}
	}

}

int main() {

	int n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];


	counting_sort(arr, n);

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	return 0;
}