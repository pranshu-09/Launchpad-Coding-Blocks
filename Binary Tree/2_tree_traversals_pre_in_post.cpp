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


// PreOrder Traversal (Root, Left, Right)
void preorder_print(node*root) {

	if (root == NULL) {
		return;
	}

	cout << root->data << " ";
	preorder_print(root->left);
	preorder_print(root->right);
}


// Inorder Traversal (Left, Root, Right)
void inorder_print(node*root) {

	if (root == NULL) {
		return;
	}

	inorder_print(root->left);
	cout << root->data << " ";
	inorder_print(root->right);
}


// Postorder Traversal (Left, Right, Root)
void postorder_print(node*root) {

	if (root == NULL) {
		return;
	}

	postorder_print(root->left);
	postorder_print(root->right);
	cout << root->data << " ";
}

int main() {

	node*root = build_tree();

	cout << endl;

	cout << "PreOrder Traversal of Tree" << endl;
	preorder_print(root);
	cout << endl << endl;

	cout << "IneOrder Traversal of Tree" << endl;
	inorder_print(root);
	cout << endl << endl;

	cout << "PostOrder Traversal of Tree" << endl;
	postorder_print(root);
	cout << endl;

	return 0;
}