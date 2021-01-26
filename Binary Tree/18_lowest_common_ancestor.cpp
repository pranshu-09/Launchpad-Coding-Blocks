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

node*lca(node*root, int a, int b) {

	if (root == NULL) {
		return NULL;
	}

	// If current is either a or b
	if (root->data == a or root->data == b) {
		return root;
	}

	// Else call for left and right
	node*left_ans = lca(root->left, a, b);
	node*right_ans = lca(root->right, a, b);

	// If both the ans returned by left and right are not NULL, this means current node is the LCA
	if (left_ans != NULL and right_ans != NULL) {
		return root;
	}

	// If one of the answers is NULL, then we will return the node that is not NULL
	if (left_ans != NULL) {
		return left_ans;
	}

	return right_ans;
}

int main() {

	node*root = build_tree();
	bfs_print(root);

	int a, b;
	cin >> a >> b;

	node*ans = lca(root, a, b);

	cout << "LCA of " << a << " and " << b << " is " << ans->data;

	return 0;
}