#include<iostream>
using namespace std;

int first_occurence(int arr[], int n, int key) {

	int start = 0;
	int end = n - 1;

	int ans = -1;

	// Update in the direction in which the ans value gets lower and lower

	while (start <= end) {

		int mid = (end + start) / 2;

		if (arr[mid] == key) {

			ans = mid;
			end = mid - 1;		// By updating end, we would see if there's another key value present in left of mid
		}
		else if (arr[mid] > key) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}

	return ans;
}

int last_occurence(int arr[], int n, int key) {

	int start = 0;
	int end = n - 1;

	int ans = -1;

	// Update in the direction in which the ans value gets lower and lower

	while (start <= end) {

		int mid = (end + start) / 2;

		if (arr[mid] == key) {

			ans = mid;
			start = mid + 1;				// Don't stop and explore the right part of the array if there is another key in the right of the array
		}
		else if (arr[mid] > key) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}

	return ans;
}

int main() {

	int n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int key;
	cin >> key;

	cout << first_occurence(arr, n, key) << endl;
	cout << last_occurence(arr, n, key) << endl;


}