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

void bfs_print(node*root) {

	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while (!q.empty()) {

		node*f = q.front();

		if (f == NULL) {

			cout << endl;
			q.pop();
			if (!q.empty()) {
				q.push(NULL);
			}
		}
		else {
			cout << f->data << " ";
			q.pop();

			if (f->left) {
				q.push(f->left);
			}

			if (f->right) {
				q.push(f->right);
			}
		}
	}
}

void left_view_binary_tree(node*root, int curr_level, int &max_level) {

	if (root == NULL) {
		return;
	}

	if (curr_level > max_level) {
		cout << root->data << " ";
		max_level = curr_level;
	}

	left_view_binary_tree(root->left, curr_level + 1, max_level);
	left_view_binary_tree(root->right, curr_level + 1, max_level);
}

void left_view_queue(node*root) {

	queue<node*>q;
	q.push(root);

	while (!q.empty()) {

		int n = q.size();

		for (int i = 1; i <= n; i++) {
			node*f = q.front();
			q.pop();

			if (i == 1) {
				cout << f->data << " ";
			}

			if (f->left) {
				q.push(f->left);
			}

			if (f->right) {
				q.push(f->right);
			}
		}
	}
}

istream& operator>>(istream&is, node*&root) {
	root = build_tree();
	return is;
}

ostream& operator<<(ostream&os, node*root) {
	bfs_print(root);
	return os;
}

int main() {

	node*root = NULL;

	cin >> root;

	cout << root << endl;

	// Using Recursion
	int max_level = -1;
	left_view_binary_tree(root, 0, max_level);

	cout << endl;

	// Using Queue
	left_view_queue(root);

	return 0;
}