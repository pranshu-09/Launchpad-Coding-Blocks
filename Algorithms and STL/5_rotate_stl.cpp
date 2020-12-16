#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {

	int arr[] = {10, 20, 30, 40, 50, 60};
	int n = 6;

	// Rotate at index 2 -> Desired Array -> 30 40 50 60 10 20
	rotate(arr, arr + 2, arr + n);

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;


	// Similarly applying for vector
	vector<int> v{10, 20, 30, 40, 50, 60};

	rotate(v.begin(), v.begin() + 3, v.end());

	for (int x : v)
		cout << x << " ";
	cout << endl;



	// Next Permutation
	vector<int> ax{1, 2, 3, 4};

	int i = 4;
	while (i--) {
		next_permutation(ax.begin(), ax.end());
		for (int x : ax)
			cout << x << " ";
		cout << endl;
	}

}