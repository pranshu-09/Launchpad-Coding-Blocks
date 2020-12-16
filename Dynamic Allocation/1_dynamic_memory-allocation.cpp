#include<iostream>
using namespace std;

int main() {

	// Allocation
	int b[100];
	cout << sizeof(b) << endl;


	// Dynamic Memory Allocation
	int n;
	cin >> n;
	int *a = new int[n];
	cout << sizeof(a) << endl;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cout << a[i] << " ";
	}

	// Free Up the space
	delete [] a;

}