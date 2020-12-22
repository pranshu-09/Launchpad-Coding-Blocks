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


// Get the node to be deleted
node*get_node(node*head, int data) {

	node*temp = head;

	while (temp->next != head) {

		if (temp->data == data) {
			return temp;
		}

		temp = temp->next;
	}

	if (temp->data == data) {
		return temp;
	}

	return NULL;
}


// Deletion
void delete_circular_ll(node*&head, int data) {

	node*to_delete = get_node(head, data);

	if (to_delete == NULL) {
		return;
	}

	if (head == to_delete) {
		head = head->next;
	}

	node*temp = head;

	while (temp->next != to_delete) {
		temp = temp->next;
	}

	temp->next = to_delete->next;
	delete to_delete;
}

int main() {

	node*head = NULL;

	insert(head, 1);
	insert(head, 2);
	insert(head, 3);
	insert(head, 4);
	insert(head, 5);

	print_ll(head);
	cout << endl;

	delete_circular_ll(head, 3);
	print_ll(head);
	cout << endl;

	delete_circular_ll(head, 5);
	print_ll(head);
	cout << endl;
}