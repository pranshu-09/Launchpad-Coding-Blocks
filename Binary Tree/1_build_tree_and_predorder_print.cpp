#include<iostream>
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

node*build_tree() {

	int d;
	cin >> d;

	if (d == -1) {
		return NULL;
	}

	node*root = new node(d);
	root->left = build_tree();
	root->right = build_tree();

	return root;
}

void print_tree(node*root) {

	if (root == NULL) {
		return;
	}

	cout << root->data << " ";
	print_tree(root->left);
	print_tree(root->right);
}

int main() {

	node*root = build_tree();

	print_tree(root);

	return 0;
}