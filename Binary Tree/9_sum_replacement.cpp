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

int sum_replacement(node*root) {

	if (root == NULL) {
		return 0;
	}

	// As we do not need to change the data of leaf nodes
	if (root->left == NULL and root->right == NULL) {
		return root->data;
	}

	// Store the data of root first
	int x = root->data;

	// Calculate left sum and right sum
	int left_sum = sum_replacement(root->left);
	int right_sum = sum_replacement(root->right);

	root->data = left_sum + right_sum;

	return (x + left_sum + right_sum);
}

void preorder_print(node*root) {

	if (root == NULL)
		return;

	cout << root->data << " ";
	preorder_print(root->left);
	preorder_print(root->right);
}

int main() {

	node*root = build_tree();

	int sum = sum_replacement(root);

	preorder_print(root);

	return 0;
}
