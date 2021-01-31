#include<iostream>
#include<queue>
using namespace std;

class node {

public:
	int data;
	node*left;
	node*right;

	node(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

node*insert_in_bst(node*root, int d) {

	if (root == NULL) {
		root = new node(d);
		return root;
	}

	if (d <= root->data) {
		root->left = insert_in_bst(root->left, d);
	}
	else {
		root->right = insert_in_bst(root->right, d);
	}

	return root;
}

node*build_bst() {

	int d;
	cin >> d;

	node*root = NULL;

	while (d != -1) {
		root = insert_in_bst(root, d);
		cin >> d;
	}

	return root;
}

void bfs_print(node*root) {

	queue<node*>q;
	q.push(root);
	q.push(NULL);

	while (!q.empty()) {

		node*f = q.front();
		q.pop();

		if (f == NULL) {
			cout << endl;
			if (!q.empty()) {
				q.push(NULL);
			}
		}
		else {
			cout << f->data << " ";

			if (f->left) {
				q.push(f->left);
			}

			if (f->right) {
				q.push(f->right);
			}
		}
	}
}

void inorder(node*root) {

	if (root == NULL) {
		return;
	}

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

class Linked_list {

public:
	node*head;
	node*tail;
};


Linked_list flatten(node*root) {

	Linked_list l;

	if (root == NULL) {
		l.head = l.tail = NULL;
		return l;
	}

	if (root->left == NULL and root->right == NULL) {							// Leaf Node
		l.head = l.tail = root;
		return l;
	}

	if (root->left != NULL and root->right == NULL) {							// Left not NULL

		Linked_list left = flatten(root->left);

		left.tail->right = root;

		l.head = left.head;
		l.tail = root;

		return l;
	}

	if (root->left == NULL and root->right != NULL) {
		Linked_list right = flatten(root->right);

		root->right = right.head;

		l.head = root;
		l.tail = right.tail;

		return l;
	}

	if (root->left != NULL and root->right != NULL) {

		Linked_list left = flatten(root->left);
		Linked_list right = flatten(root->right);

		left.tail->right = root;
		root->right = right.head;

		l.head = left.head;
		l.tail = right.tail;

		return l;
	}
}

int main() {

	node*root = build_bst();

	bfs_print(root);
	cout << endl;

	inorder(root);
	cout << endl;

	Linked_list final = flatten(root);

	node*temp = final.head;

	while (temp != NULL) {
		cout << temp->data << " -> ";
		temp = temp->right;
	}

	return 0;
}