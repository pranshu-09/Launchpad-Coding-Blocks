#include<iostream>
#include<queue>
#include<climits>
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

bool is_bst(node*root, int min_val = INT_MIN, int max_val = INT_MAX) {

	if (root == NULL) {
		return true;
	}

	if ((min_val <= root->data and root->data <= max_val) and is_bst(root->left, min_val, root->data) and is_bst(root->right, root->data, max_val)) {
		return true;
	}

	return false;
}

int main() {

	node*root = build_bst();
	bfs_print(root);

	if (is_bst(root)) {
		cout << "It is a BST";
	}
	else {
		cout << "It is not a BST";
	}
}