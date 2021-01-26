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

	return max(left_height, right_height) + 1;
}

bool check_balanced_tree_top_down(node*root) {

	if (root == NULL) {
		return true;
	}

	int left_height = height(root->left);
	int right_height = height(root->right);

	if (abs(left_height - right_height) <= 1 and check_balanced_tree_top_down(root->left) and check_balanced_tree_top_down(root->right)) {
		return true;
	}
	else {
		return false;
	}
}


// Bottom Up Approach
class Pair {

public:
	int height;
	bool balanced;
};

Pair check_balanced_tree_bottom_up(node*root) {

	Pair p;

	if (root == NULL) {
		p.height = 0;
		p.balanced = true;
		return p;
	}

	Pair left = check_balanced_tree_bottom_up(root->left);
	Pair right = check_balanced_tree_bottom_up(root->right);

	p.height = max(left.height, right.height) + 1;

	if (abs(left.height - right.height) <= 1 and left.balanced and right.balanced) {
		p.balanced = true;
	}
	else {
		p.balanced = false;
	}

	return p;
}


int main() {

	node*root = build_tree();

	// Top Down Approach
	if (check_balanced_tree_top_down(root)) {
		cout << "Tree is height balanced" << endl;
	}
	else {
		cout << "Tree is not height balanced" << endl;
	}

	// Bottom Up Approach

	Pair ans = check_balanced_tree_bottom_up(root);
	if (ans.balanced == true) {
		cout << "Tree is height balanced" << endl;
	}
	else {
		cout << "Tree is not height balanced" << endl;
	}

}