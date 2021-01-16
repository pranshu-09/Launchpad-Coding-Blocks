#include<iostream>
#include<list>
using namespace std;

class Queue {

	int curr_size;
	list<int> l;

public:

	Queue() {
		curr_size = 0;
	}

	void push(int data) {
		curr_size++;
		l.push_back(data);
	}

	bool empty() {
		return curr_size == 0;
	}

	void pop() {
		if (!empty()) {
			curr_size--;
			l.pop_front();
		}
	}

	int front() {
		return l.front();
	}
};

int main() {

	Queue q;

	for (int i = 1; i <= 10; i++)
		q.push(i);

	q.pop();
	q.pop();

	while (!q.empty()) {
		cout << q.front() << endl;
		q.pop();
	}

	return 0;
}