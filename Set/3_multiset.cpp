#include<iostream>
#include<set>
using namespace std;


typedef multiset<int>::iterator It;


int main() {

	int arr[] = {10, 20, 30, 20, 10, 10};
	int n = 6;

	multiset<int> m(arr, arr + n);

	for (auto p : m) {
		cout << p << " ";
	}
	cout << endl;


	// Erase
	m.erase(20);

	for (auto p : m) {
		cout << p << " ";
	}
	cout << endl;


	// Insert
	m.insert(80);
	for (auto p : m) {
		cout << p << " ";
	}
	cout << endl;


	// Count
	cout << "Count of 10 is " << m.count(10) << endl;

	// Find
	auto it = m.find(10);
	cout << (*it) << endl;


	// Find all occurences of an element
	pair<It, It> range = m.equal_range(10);
	for (auto it = range.first; it != range.second; it++) {
		cout << *it << " ";
	}
	cout << endl;


	// Lower and Upper Bound
	for (auto it = m.lower_bound(10); it != m.upper_bound(77); it++) {
		cout << *it << " ";
	}
	cout << endl;

	return 0;
}