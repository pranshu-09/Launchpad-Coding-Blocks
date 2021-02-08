#include<iostream>
#include<queue>
using namespace std;

class Person {

public:
	string name;
	int age;

	Person(string s, int n) {
		name = s;
		age = n;
	}
};

class PersonCompare {
public:
	bool operator()(Person a, Person b) {
		return a.age < b.age;
	}
};

int main() {

	priority_queue<Person, vector<Person>, PersonCompare > pq;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {

		string s;
		int n;
		cin >> s >> n;

		Person p(s, n);

		pq.push(p);
	}

	int k;
	cin >> k;

	for (int i = 0; i < k; i++) {

		Person p = pq.top();
		cout << p.name << " " << p.age << endl;

		pq.pop();
	}

	return 0;
}