#include<iostream>
#include<vector>

using namespace std;

template <typename T>

class Stack {

private:
	vector<T> v;

public:

	void push(T data) {
		v.push_back(data);
	}

	bool empty() {
		return v.size() == 0;
	}

	void pop() {
		if (!empty())
			v.pop_back();
	}

	T top() {
		return v[v.size() - 1];
	}
};

int main() {

	Stack<string> s;

	for (int i = 1; i <= 5; ++i) {
		string str;
		cin >> str;
		s.push(str);
	}

	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}

}