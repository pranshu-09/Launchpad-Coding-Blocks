#include<iostream>
#include<stack>

using namespace std;

void transfer(stack<int> &s1, stack<int> &s2, int n) {

	for (int i = 0; i < n; i++) {
		s2.push(s1.top());
		s1.pop();
	}
}

int main() {

	int n;
	cin >> n;

	stack<int> s1;
	stack<int> s2;

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


	// Stack reversal using 1 extra stack
	for (int i = 0; i < n; i++) {

		int x = s1.top();
		s1.pop();

		int n_transfer = n - i - 1;

		transfer(s1, s2, n_transfer);

		s1.push(x);

		transfer(s2, s1, n_transfer);

	}

	cout << "Stack after Reversal" << endl;
	while (!s1.empty()) {
		cout << s1.top() << " ";
		s1.pop();
	}
	cout << endl;

	return 0;
}