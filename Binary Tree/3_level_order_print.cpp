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

	if (d == -1)
		return NULL;

	node*root = new node(d);
	root->left = build_tree();
	root->right = build_tree();

	return root;
}


int height_tree(node*root) {

	if (root == NULL) {
		return 0;
	}

	int left_height = height_tree(root->left);
	int right_height = height_tree(root->right);

	int total_height = max(left_height, right_height) + 1;

	return total_height;
}

void print_kth_level(node*root, int k) {

	if (root == NULL) {
		return;
	}

	if (root != NULL and k == 1) {
		cout << root->data << " ";
		return;
	}

	print_kth_level(root->left, k - 1);
	print_kth_level(root->right, k - 1);
}

void level_order_print(node*root) {

	int h = height_tree(root);

	for (int k = 1; k <= h; k++) {
		print_kth_level(root, k);
		cout << endl;
	}
}

int main() {

	node*root = build_tree();

	level_order_print(root);

	return 0;
}