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

void bfs_traversal(node*root) {

	queue<node*>q;

	q.push(root);

	while (!q.empty()) {

		node*f = q.front();

		cout << f->data << " ";
		q.pop();

		if (f->left != NULL) {
			q.push(f->left);
		}

		if (f->right != NULL) {
			q.push(f->right);
		}
	}
}

int main() {

	node*root = build_tree();

	bfs_traversal(root);

	return 0;
}