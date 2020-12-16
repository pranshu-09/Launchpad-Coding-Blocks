#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	int n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int key;
	cin >> key;

	bool present = binary_search(arr, arr + n, key);

	if (present)
		cout << "Present" << endl;
	else
		cout << "Absent" << endl;

	auto it = lower_bound(arr, arr + n, key);
	cout << "Lower Bound -> " << (it - arr) << " " << arr[it - arr] << endl;

	auto it2 = upper_bound(arr, arr + n, key);
	cout << "Upper Bound -> " << (it2 - arr) << endl;

}