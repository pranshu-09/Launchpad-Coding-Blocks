#include<iostream>
#include<list>

using namespace std;

int main() {

	list<int> l{1, 2, 3, 4, 5};

	// Different Datatype
	list<string> l2{"facebook", "amazon", "apple", "netflix", "google"};

	// Push function
	l2.push_back("adobe");


	// Sort function of List
	l2.sort();

	// Reverse the list
	l2.reverse();

	// Pop front
	cout << l2.front() << endl;
	l2.pop_front();

	// add to the front of the list
	l2.push_front("goldman sachs");
	cout << l2.back() << endl;
	l2.pop_back();


	// Iterate over the list
	for (auto s : l2) {
		cout << s << " -> ";
	}

	cout << endl;


	for (auto it = l2.begin(); it != l2.end(); it++) {
		cout << (*it) << " -> ";
	}
}