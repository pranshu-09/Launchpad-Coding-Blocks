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

int return_count(node*root) {

	if (root == NULL) {
		return 0;
	}

	int count_left = return_count(root->left);
	int count_right = return_count(root->right);

	int total_count = count_left + count_right + 1;

	return total_count;
}

int return_sum(node*root) {

	if (root == NULL) {
		return 0;
	}

	int sum_left = return_sum(root->left);
	int sum_right = return_sum(root->right);

	int total_sum = sum_left + sum_right + root->data;

	return total_sum;
}

int main() {

	node*root = build_tree();

	int nodes = return_count(root);
	int sum = return_sum(root);

	cout << "No of Nodes = " << nodes << endl;
	cout << "Sum of all the nodes = " << sum << endl;

	return 0;
}