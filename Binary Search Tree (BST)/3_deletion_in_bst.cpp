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

node*insert_in_bst(node*root, int data) {

	if (root == NULL) {
		root = new node(data);
		return root;
	}

	if (data <= root->data) {
		root->left = insert_in_bst(root->left, data);
	}
	else {
		root->right = insert_in_bst(root->right, data);
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

void inorder(node*root) {

	if (root == NULL)
		return;

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
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


node*delete_in_bst(node*root, int data) {

	if (root == NULL) {
		return NULL;
	}

	if (data < root->data) {
		root->left = delete_in_bst(root->left, data);
		return root;
	}
	else if (data == root->data) {

		// Case 1 : 0 children
		if (root->left == NULL and root->right == NULL) {
			delete root;
			return NULL;
		}

		// Case 2 : 1 children
		else if (root->left != NULL and root->right == NULL) {
			node*temp = root->left;
			delete root;
			return temp;
		}

		else if (root->right != NULL and root->left == NULL) {
			node*temp = root->right;
			delete root;
			return temp;
		}

		// Case 3 : 2 children
		else {

			node*replace = root->right;

			while (replace->left != NULL) {
				replace = replace->left;
			}

			root->data = replace->data;
			root->right = delete_in_bst(root->right, replace->data);
			return root;
		}
	}
	else {
		root->right = delete_in_bst(root->right, data);
		return root;
	}
}

int main() {

	node*root = build_bst();

	bfs_print(root);
	cout << endl;

	inorder(root);
	cout << endl;

	int search;
	cin >> search;

	root = delete_in_bst(root, search);

	bfs_print(root);
	cout << endl;

	inorder(root);
	cout << endl;

	return 0;
}