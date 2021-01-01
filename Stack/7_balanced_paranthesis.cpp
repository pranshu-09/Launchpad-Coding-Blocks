#include<iostream>
#include<stack>

using namespace std;

bool balanced_paranthesis(string str) {

	stack<char> s;

	for (int i = 0; i < str.size(); i++) {

		if (str[i] == '(') {
			s.push(str[i]);
		}

		else if (str[i] == ')') {
			if (s.empty() or s.top() != '(')
				return false;

			s.pop();
		}
	}

	return s.empty();
}

int main() {

	string s;
	cin >> s;

	bool is_balanced = balanced_paranthesis(s);

	if (is_balanced) {
		cout << "Paranthesis are balanced";
	}
	else {
		cout << "Paranthesis not balanced";
	}

	return 0;
}