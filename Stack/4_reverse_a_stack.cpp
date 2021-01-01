#include<iostream>
#include<stack>

using namespace std;

void transfer(stack<int> &s1, stack<int> &s2) {

	while (!s1.empty()) {
		s2.push(s1.top());
		s1.pop();
	}
}

int main() {

	stack<int> s1;
	stack<int> s2;
	stack<int> s3;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		s1.push(p);
	}

	stack<int> temp = s1;

	cout << "Original Stack" << endl;
	while (!temp.empty()) {
		cout << temp.top() << " ";
		temp.pop();
	}
	cout << endl;

	transfer(s1, s2);
	transfer(s2, s3);
	transfer(s3, s1);

	cout << "Stack after Reversal" << endl;
	while (!s1.empty()) {
		cout << s1.top() << " ";
		s1.pop();
	}
	cout << endl;

	return 0;
}