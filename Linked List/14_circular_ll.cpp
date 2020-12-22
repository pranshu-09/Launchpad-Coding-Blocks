#include<iostream>
using namespace std;

class node {

public:
	int data;
	node*next;

	node(int d) {
		this->next = NULL;
		this->data = d;
	}

};

void insert(node*&head, int data) {

	node*n = new node(data);
	node*temp = head;

	n->next = head;

	if (temp != NULL) {

		while (temp->next != head) {
			temp = temp->next;
		}

		temp->next = n;
	}
	else {

		n->next = n;
	}

	head = n;
}

void print_ll(node*head) {

	node*temp = head;

	while (temp->next != head) {
		cout << temp -> data << " -> ";
		temp = temp->next;
	}

	cout << temp->data;
}

int main() {

	node*head = NULL;

	insert(head, 1);
	insert(head, 2);
	insert(head, 3);
	insert(head, 4);
	insert(head, 5);

	print_ll(head);
}