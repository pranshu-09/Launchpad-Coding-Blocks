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

	if (root == NULL) {
		return;
	}

	queue<node*>q;
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

void helper(node*root, node*&head, node*&prev) {

	if (root == NULL) {
		return;
	}

	helper(root->left, head, prev);

	if (prev == NULL) {
		head = root;
	}
	else {
		root->left = prev;
		prev->right = root;
	}
	prev = root;

	helper(root->right, head, prev);
}

node * bToDLL(node *root)
{
	node*head = NULL;
	node*prev = NULL;
	// your code here
	helper(root, head, prev);

	return head;
}

int main() {

	node*root = build_tree();
	bfs_print(root);

	node* dll_head = bToDLL(root);

	return 0;
}
