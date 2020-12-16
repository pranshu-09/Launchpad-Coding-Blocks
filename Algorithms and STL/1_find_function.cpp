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

	auto it = find(arr, arr + n, key);

	// cout << it << endl;		// Address of the Key Element

	int index = it - arr;
	// cout << index << endl;		// Index of the key element


	if (index == n) {
		cout << key << " not found";
	}
	else {
		cout << key << " present at " << index;
	}

	return 0;
}
