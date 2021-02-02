#include<iostream>
#include<set>
using namespace std;

int main() {

	int n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	set<int> s;

	for (int i = 0; i < n; i++)
		s.insert(arr[i]);

	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
		cout << (*it) << " ";
	}
	cout << endl;

	// Erase elements
	int elem;
	cin >> elem;

	// Method 1
	s.erase(elem);

	// Method 2
	int elem2;
	cin >> elem2;

	auto it = s.find(elem2);
	s.erase(it);

	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
		cout << (*it) << " ";
	}
	cout << endl;

	return 0;
}