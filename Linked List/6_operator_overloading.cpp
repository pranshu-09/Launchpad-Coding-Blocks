#include<iostream>
using namespace std;

class node {

public:
	int data;
	node*next;

	// Constructor
	node(int d) {
		this->data = d;
		this->next = NULL;
	}

};


void insert_at_head(node*&head, int d) {

	if (head == NULL) {
		head = new node(d);
		return;
	}

	node*n = new node(d);
	n->next = head;
	head = n;

}

int length(node*head) {
	int size = 0;

	while (head != NULL) {
		size++;
		head = head->next;
	}

	return size;
}

void insert_at_tail(node*&head, int data) {
	if (head == NULL) {
		head = new node(data);
		return;
	}

	node*tail = head;

	while (tail->next != NULL) {
		tail = tail->next;
	}

	tail->next = new node(data);
}

void insert_at_middle(node*&head, int d, int p) {

	if (head == NULL or p == 0) {
		insert_at_head(head, d);
	}
	else if (p > length(head)) {
		insert_at_tail(head, d);
	}
	else {

		// Jump p-1 times
		int jump = 1;
		node*temp = head;

		while (jump <= p - 1) {
			temp = temp->next;
			jump++;
		}

		node*n = new node(d);
		n->next = temp->next;
		temp->next = n;
	}

}

node* take_input() {

	int d;
	cin >> d;

	node*head = NULL;

	while (d != -1) {
		insert_at_head(head, d);
		cin >> d;
	}

	return head;
}

void print_ll(node*head) {

	while (head != NULL) {
		cout << head->data << " -> ";
		head = head->next;
	}

	cout << endl;
}


// void operator<<(ostream &os, node*head) {
// 	print_ll(head);
// }

ostream& operator<<(ostream&os, node*head) {
	print_ll(head);
	return os;
}

istream& operator>>(istream&is, node*&head) {
	head = take_input();
	return is;
}

int main() {

	// node*head = take_input();

	// node*head2 = take_input();

	// cout << head;
	// cout << head2;

	node*head;
	node*head2;
	cin >> head >> head2;

	cout << head << "AH YES" << endl << head2;

	return 0;
}