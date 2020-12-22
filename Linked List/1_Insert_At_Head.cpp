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


void print_ll(node*head) {

	while (head != NULL) {
		cout << head->data << " -> ";
		head = head->next;
	}

	cout << endl;
}

int main() {

	node*head = NULL;

	insert_at_head(head, 3);
	insert_at_head(head, 2);
	insert_at_head(head, 1);
	insert_at_head(head, 0);

	print_ll(head);

	return 0;
}