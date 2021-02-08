#include<iostream>
using namespace std;

class Fun {

public:

	void operator()() {
		cout << "You Have what it takes" << endl;
	}

	void operator()(string s) {
		cout << "You Have what it takes " << s << endl;
	}
};

int main() {

	Fun f;

	f();

	// Passing string
	f("to crack Amazon");

	return 0;
}