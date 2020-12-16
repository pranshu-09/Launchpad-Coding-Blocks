#include<iostream>
#include<vector>
using namespace std;

class Student {

public:
	int marks;
	string name;
};

void bucket_sort(Student s[], int n) {

	vector<Student> v[101];

	for (int i = 0; i < n; i++) {
		int m = s[i].marks;

		v[m].push_back(s[i]);
	}

	for (int i = 100; i >= 0; i--) {

		for (auto x : v[i]) {
			cout << x.name << " -> " << x.marks << endl;
		}

	}
}

int main() {

	int n;
	cin >> n;

	Student s[n];
	for (int i = 0; i < n; i++) {
		cin >> s[i].marks >> s[i].name;
	}

	bucket_sort(s, n);

	return 0;
}