#include<iostream>
#include<stack>
using namespace std;

template <typename T>
class Queue {

	stack<T> s1, s2;

public:

	void push(T x) {
		s1.push(x);
	}

	void pop() {

		if (s1.empty())
			return;

		// Push N-1 elements to s2
		while (s1.size() > 1) {
			s2.push(s1.top());
			s1.pop();
		}

		//Pop the first inserted element
		s1.pop();

		while (!s2.empty()) {
			s1.push(s2.top());
			s2.pop();
		}
	}

	T front() {

		// Push N-1 elements to s2
		while (s1.size() > 1) {
			s2.push(s1.top());
			s1.pop();
		}

		T elem = s1.top();
		s1.pop();
		s2.push(elem);

		while (!s2.empty()) {
			s1.push(s2.top());
			s2.pop();
		}

		return elem;
	}

	int size() {
		return s1.size() + s2.size();
	}

	bool empty() {
		return size() == 0;
	}
};


template <typename T>
class Queue2 {

	stack<T> s1, s2;

public:

	void push(T x) {

		//Push rest of elements of s1 to s2
		while (!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}

		// Push x into s2
		s2.push(x);

		// Push all elements back to s1
		while (!s2.empty()) {
			s1.push(s2.top());
			s2.pop();
		}
	}

	void pop() {
		s1.pop();
	}

	T front() {
		return s1.top();
	}

	int size() {
		return s1.size() + s2.size();
	}

	bool empty() {
		return size() == 0;
	}
};

int main() {

	Queue2<int> q;

	q.push(1);
	q.push(4);
	q.push(9);
	q.push(2);
	q.push(7);

	// q.pop();

	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}

	return 0;
}