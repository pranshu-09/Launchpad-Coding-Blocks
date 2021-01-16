#include<iostream>
using namespace std;

class node {

public:
	int data;
	node*next;

	node(int data) {
		this->data = data;
		this->next = NULL;
	}
};

class Queue {

	node*front;
	node*rear;
	int curr_size;

public:

	Queue() {
		front = rear = NULL;
		curr_size = 0;
	}

	void enque(int data) {

		node*temp = new node(data);

		if (front == NULL) {
			front = rear = temp;
		}
		else {
			rear->next = temp;
			rear = temp;
		}

		curr_size++;
	}

	void deque() {

		if (front == NULL)
			return;

		node*temp = front;
		front = front->next;

		if (front == NULL)
			rear = NULL;

		delete temp;
		curr_size--;
	}

	bool empty() {
		return curr_size == 0;
	}

	int return_front() {
		return front->data;
	}

};

int main() {

	Queue q;

	q.enque(1);
	q.enque(87);
	q.enque(76);
	q.enque(2);
	q.enque(9);
	q.enque(3);
	q.enque(8);

	q.deque();
	q.deque();
	q.enque(11);
	q.deque();

	while (!q.empty()) {
		cout << q.return_front() << endl;
		q.deque();
	}

	return 0;
}
