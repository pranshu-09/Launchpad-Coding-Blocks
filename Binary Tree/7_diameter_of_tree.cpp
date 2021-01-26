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

int height(node*root) {

	if (root == NULL) {
		return 0;
	}

	int left_height = height(root->left);
	int right_height = height(root->right);

	int curr_height = max(left_height, right_height) + 1;

	return curr_height;
}

int diameter(node*root) {

	if (root == NULL) {
		return 0;
	}

	int h1 = height(root->left);
	int h2 = height(root->right);

	int option_1 = h1 + h2;
	int option_2 = diameter(root->left);
	int option_3 = diameter(root->right);

	return max(option_1, max(option_2, option_3));
}

int main() {

	node*root = build_tree();

	cout << "Diameter of the tree is " << diameter(root) << endl;

	return 0;
}
