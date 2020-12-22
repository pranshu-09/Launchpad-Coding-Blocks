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


void delete_at_head(node*&head) {

	if (head == NULL)
		return;

	node*temp = head->next;
	delete head;
	head = temp;

}

void delete_at_tail(node*&head) {

	if (head == NULL)
		return;

	node*tail = head;

	while (tail->next->next != NULL) {
		tail = tail->next;
	}

	node*n = tail->next;
	tail->next = NULL;
	delete n;
}

void delete_at_middle(node*&head, int p) {

	if (head == NULL)
		return;

	if (p == 0) {
		delete_at_head(head);
	}

	if (p > length(head)) {
		delete_at_tail(head);
	}


	int jump = 1;
	node*temp = head;

	while (jump <= p - 1) {
		temp = temp->next;
		jump++;
	}

	node*n = temp->next;
	temp->next = n->next;
	delete n;
}


bool search(node*head, int key) {

	node*temp = head;

	while (temp != NULL) {
		if (temp->data == key) {
			return true;
		}

		temp = temp->next;
	}

	return false;
}

bool search_recursive(node*head, int key) {

	// Base Case
	if (head == NULL) {
		return false;
	}

	if (head->data == key) {
		return true;
	}
	else {
		return search_recursive(head->next, key);
	}

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

	insert_at_middle(head, 8, 2);
	print_ll(head);

	insert_at_tail(head, 11);
	print_ll(head);

	// delete_at_head(head);
	// delete_at_tail(head);
	// delete_at_middle(head, 1);
	// print_ll(head);


	int key;
	cin >> key;

	if (search(head, key)) {
		cout << "Element found" << endl;
	}
	else {
		cout << "Element not found" << endl;
	}


	if (search_recursive(head, key)) {
		cout << "Element found" << endl;
	}
	else {
		cout << "Element not found" << endl;
	}


	return 0;
}