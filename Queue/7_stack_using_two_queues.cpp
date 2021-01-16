#include<iostream>
#include<queue>
using namespace std;

template<typename T>

// Pop Expensive Method
class Stack {

	queue<T> q1, q2;

public:

	void push(T x) {
		q1.push(x);
	}

	void pop() {

		if (q1.empty())
			return;

		// Push N-1 elements to q2
		while (q1.size() > 1) {
			q2.push(q1.front());
			q1.pop();
		}

		// Remove Nth element
		q1.pop();

		swap(q1, q2);
	}

	T top() {

		while (q1.size() > 1) {
			q2.push(q1.front());
			q1.pop();
		}

		T elem = q1.front();
		q1.pop();

		// Insert the Nth element to q2
		q2.push(elem);

		swap(q1, q2);

		return elem;
	}

	int size() {
		return q1.size() + q2.size();
	}

	bool empty() {
		return size() == 0;
	}
};


// Push Expensive Method
template <typename T>
class Stack2 {

	queue<T> q1, q2;

public:

	void push(T x) {

		//Push x to q2
		q2.push(x);

		//Push all elements of q1 to q2
		while (!q1.empty()) {
			q2.push(q1.front());
			q1.pop();
		}

		swap(q1, q2);
	}

	void pop() {

		if (q1.empty())
			return;

		q1.pop();
	}

	T top() {
		return q1.front();
	}

	int size() {
		return q1.size() + q2.size();
	}

	bool empty() {
		return size() == 0;
	}

};

int main() {

	Stack2<int> s;

	s.push(1);
	s.push(-2);
	s.push(8);
	s.push(2);
	s.push(6);

	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}

	return 0;
}