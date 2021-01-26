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
		this-> right = NULL;
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

			if (f->left)
				q.push(f->left);

			if (f->right)
				q.push(f->right);
		}
	}
}

void print_k_level(node*root, int k) {

	if (root == NULL)
		return;

	if (k == 0) {
		cout << root->data << " ";
		return;
	}

	print_k_level(root->left, k - 1);
	print_k_level(root->right, k - 1);
}


int nodes_at_distance_k(node*root, int k, node*target) {

	if (root == NULL) {
		return -1;
	}

	if (root == target) {
		print_k_level(root, k);
		return 0;
	}

	int left_distance = nodes_at_distance_k(root->left, k, target);

	if (left_distance != -1) {

		if (left_distance + 1 == k) {					// If ancestor node is at distance k
			cout << root->data << " ";
		}
		else {										// If we have to go right
			int right_d = k - 2 - left_distance;
			print_k_level(root->right, right_d);
		}

		return left_distance + 1;
	}

	// If node not present in left subtree, we check in right subtree
	int right_distance = nodes_at_distance_k(root->right, k, target);

	if (right_distance != -1) {

		if (right_distance + 1 == k) {
			cout << root->data << " ";
		}
		else {
			int left_d = k - 2 - right_distance;
			print_k_level(root->left, left_d);
		}

		return right_distance + 1;
	}

	// If target is not present in left and not in right, we will just return -1
	return -1;
}


int main() {

	node*root = build_tree();

	int k;
	cin >> k;

	node*target = root->left->left;

	nodes_at_distance_k(root, k, target);
}