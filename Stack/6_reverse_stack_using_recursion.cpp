#include<iostream>
#include<stack>

using namespace std;

void insert_at_bottom(stack<int>&s, int x) {

	if (s.empty()) {
		s.push(x);
		return;
	}

	int y = s.top();
	s.pop();
	insert_at_bottom(s, x);
	s.push(y);
}

void reverse_stack(stack<int>&s) {

	if (s.empty())
		return;

	int x = s.top();
	s.pop();
	reverse_stack(s);
	insert_at_bottom(s, x);
}

int main() {

	stack<int>s;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		s.push(p);
	}

	stack<int> temp = s;

	cout << "Original Stack" << endl;
	while (!temp.empty()) {
		cout << temp.top() << " ";
		temp.pop();
	}
	cout << endl;

	reverse_stack(s);

	cout << "Stack after Reversal" << endl;
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;


	return 0;
}