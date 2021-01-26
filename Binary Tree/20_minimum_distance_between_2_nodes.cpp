#include<iostream>
#include<queue>
#include<stack>
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


// Method 1

int path(node*root, int a, stack<node*>&s) {

	if (root == NULL) {
		return -1;
	}

	if (root->data == a) {
		s.push(root);
		return 0;
	}

	int left = path(root->left, a, s);
	if (left != -1) {
		s.push(root);
		return left + 1;
	}

	int right = path(root->right, a, s);
	if (right != -1) {
		s.push(root);
		return right + 1;
	}

	return -1;
}

int distance_between_nodes(node*root, int a, int b) {

	stack<node*>a1;
	stack<node*>b1;

	path(root, a, a1);
	path(root, b, b1);

	while (!a1.empty() and !b1.empty() and a1.top() == b1.top()) {
		a1.pop();
		b1.pop();
	}

	return a1.size() + b1.size();
}


// Method 2

node*lca(node*root, int a, int b) {

	if (root == NULL) {
		return NULL;
	}

	if (root->data == a or root->data == b) {
		return root;
	}

	node*left_node = lca(root->left, a, b);
	node*right_node = lca(root->right, a, b);

	if (left_node != NULL and right_node != NULL) {
		return root;
	}

	if (left_node != NULL) {
		return left_node;
	}

	return right_node;
}

int search(node*root, int key, int level) {

	if (root == NULL) {
		return -1;
	}

	if (root->data == key) {
		return level;
	}

	int left = search(root->left, key, level + 1);
	if (left != -1) {
		return left;
	}

	int right = search(root->right, key, level + 1);
	if (right != -1) {
		return right;
	}

	return -1;
}

int distance_between_nodes_2(node*root, int a, int b) {

	node*lca_node = lca(root, a, b);

	int l1 = search(lca_node, a, 0);
	int l2 = search(lca_node, b, 0);

	return l1 + l2;
}

int main() {

	node*root = build_tree();
	bfs_print(root);

	int a, b;
	cin >> a >> b;

	// Method 1
	int ans = distance_between_nodes(root, a, b);
	cout << "Minimum distance between " << a << " and " << b << " is " << ans << endl;

	// Method 2
	int ans_2 = distance_between_nodes_2(root, a, b);
	cout << "Minimum distance between " << a << " and " << b << " is " << ans_2 << endl;

	return 0;
}