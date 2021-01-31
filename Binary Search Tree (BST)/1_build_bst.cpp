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


void bfs_print(node*root) {

	queue<node*> q;
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

void inorder_print(node*root) {

	if (root == NULL) {
		return;
	}

	inorder_print(root->left);
	cout << root->data << " ";
	inorder_print(root->right);
}

int main() {

	node*root = build_bst();

	bfs_print(root);
	cout << endl;

	inorder_print(root);
	cout << endl;

	return 0;
}