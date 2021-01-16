#include<iostream>
using namespace std;

class Queue {

	int *arr;
	int curr_size, max_size, front, rear;

public:

	// Constructor
	Queue(int default_size = 10) {
		arr = new int[default_size];
		curr_size = 0;
		max_size = default_size;
		front = 0;
		rear = max_size - 1;
	}

	bool full() {
		return curr_size == max_size;
	}

	bool empty() {
		return curr_size == 0;
	}

	void push(int data) {
		if (!full())	{
			rear = (rear + 1) % max_size;
			arr[rear] = data;
			curr_size++;
		}
	}

	void pop() {
		if (!empty()) {
			front = (front + 1) % max_size;
			curr_size--;
		}
	}

	int return_front() {
		if (!empty())
			return arr[front];
	}

	//Destructor
	~Queue() {
		if (arr != NULL) {
			delete [] arr;
			arr = NULL;
		}
	}

};


int main() {

	Queue q;

	for (int i = 1; i <= 11; i++) {
		q.push(i);
	}

	q.pop();
	q.pop();

	q.push(12);

	while (!q.empty()) {
		cout << q.return_front() << " ";
		q.pop();
	}

	return 0;
}