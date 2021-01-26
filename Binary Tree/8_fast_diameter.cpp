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

class Pair {
public:
	int height;
	int diameter;
};

Pair fast_diameter(node*root) {

	Pair p;

	if (root == NULL) {
		p.height = p.diameter = 0;
		return p;
	}

	Pair left = fast_diameter(root->left);
	Pair right = fast_diameter(root->right);

	p.height = max(left.height, right.height) + 1;
	p.diameter = max(left.height + right.height, max(left.diameter, right.diameter));

	return p;
}

int main() {

	node*root = build_tree();

	Pair ans = fast_diameter(root);

	cout << ans.height << endl << ans.diameter << endl;

}