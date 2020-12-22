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

void reverse_ll(node*&head) {

	node*curr = head;
	node*prev = NULL;

	while (curr != NULL) {

		node*next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;

	}

	head = prev;
}

node* recursive_reverse_ll(node*head) {

	if (head->next == NULL or head == NULL) {
		return head;
	}

	node*shead = recursive_reverse_ll(head->next);

	// node*temp = shead;

	// while (temp->next !=  NULL) {
	// 	temp = temp->next;
	// }

	// node*temp = head->next;
	// temp->next = head;
	// head->next = NULL;

	head->next->next = head;
	head->next = NULL;

	// head->next = NULL;
	// temp->next = head;

	return shead;
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

istream& operator>>(istream&is,  node*&head) {
	head = take_input();
	return is;
}

ostream& operator<<(ostream&os, node*head) {
	print_ll(head);
	return os;
}

node*mid_pointt(node*head) {

	if (head == NULL or head->next == NULL) {
		return head;
	}

	node*slow = head;
	node*fast = head->next;

	while (fast != NULL and fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}

	return slow;
}

node*merge_ll(node*a, node*b) {

	if (a == NULL)
		return b;
	else if (b == NULL)
		return a;

	node*c;

	if (a->data < b->data) {
		c = a;
		c->next = merge_ll(a->next, b);
	}
	else {
		c = b;
		c->next = merge_ll(a, b->next);
	}

	return c;
}

node*merge_sort(node*head) {

	if (head->next == NULL or head == NULL)
		return head;

	node*mid = mid_pointt(head);

	node*a = head;
	node*b = mid->next;

	mid->next = NULL;

	a = merge_sort(a);
	b = merge_sort(b);

	node*c = merge_ll(a, b);
	return c;
}


int main() {


	node*head = NULL;

	cin >> head;

	cout << head;

	head = merge_sort(head);

	cout << head << endl;

	return 0;
}