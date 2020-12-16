#include<iostream>
using namespace std;

int main() {

	// Pair initialisation
	pair<int, char > p;
	p.first = 10;
	p.second = 'B';
	cout << p.first << " " << p.second << endl;


	// Creating pair from existing pair
	pair<int, char > p2(p);
	cout << p2.first << " " << p2.second << endl;


	// Using make_pair
	pair<int, string > p3 = make_pair(100, "Audi");
	cout << p3.first << " " << p3.second << endl;


	// Getting input from user
	int a, b;
	cin >> a >> b;
	pair<int, int > p4 = make_pair(a, b);
	cout << p4.first << " " << p4.second << endl;

	pair < pair<int, int > , string > car;
	car.second = "Audi";
	car.first.first = 11;
	car.first.second = 65;

	cout << car.first.first << " " << car.first.second << " " << car.second << endl;


}