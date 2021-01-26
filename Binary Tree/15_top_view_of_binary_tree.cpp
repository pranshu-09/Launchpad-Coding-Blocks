#include<iostream>
#include<map>
#include<queue>
#include<climits>
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

node* build_tree() {

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

istream& operator>>(istream&is, node*&root) {
	root = build_tree();
	return is;
}

ostream& operator<<(ostream&os, node*root) {
	bfs_print(root);
	return os;
}

void make_map(node*root, map<int, pair<int, int> >&m, int hd, int l) {

	if (root == NULL) {
		return;
	}

	// If there is no node present with the current horizontal distance
	if (m.count(hd) == 0) {
		m[hd] = make_pair(root->data, l);
	}

	// If the horizontal distance already exists but we got a node that is on a level closer to the root node
	else if (m[hd].second > l) {
		m[hd] = make_pair(root->data, l);
	}

	make_map(root->left, m, hd - 1, l + 1);
	make_map(root->right, m, hd + 1, l + 1);
}

void top_view(node*root) {

	if (root == NULL) {
		return;
	}

	map<int, pair<int, int> > m;

	make_map(root, m, 0, 0);

	for (auto x : m) {
		cout << x.second.first << " ";
	}

}

// Method-2

class node_2 {

public:
	int data;
	int hd;
	node_2*left;
	node_2*right;

	node_2(int data) {
		this->data = data;
		this->hd = INT_MAX;
		this->left = NULL;
		this->right = NULL;
	}
};

node_2* build_tree_2() {

	int d;
	cin >> d;

	if (d == -1) {
		return NULL;
	}

	node_2*root = new node_2(d);
	root->left = build_tree_2();
	root->right = build_tree_2();

	return root;
}

void top_view_queue(node_2*root) {

	if (root == NULL) {
		return;
	}

	int hd = 0;
	root->hd = hd;

	queue<node_2*>q;
	map<int, int> m;
	q.push(root);

	while (!q.empty()) {

		node_2*f = q.front();
		q.pop();

		hd = f->hd;

		if (m.count(hd) == 0) {
			m[hd] = f->data;
		}

		if (f->left) {
			f->left->hd = hd - 1;
			q.push(f->left);
		}

		if (f->right) {
			f->right->hd = hd + 1;
			q.push(f->right);
		}
	}

	for (auto x : m) {
		cout << x.second << " ";
	}
}

int main() {

	// Method 1
	// node*root = NULL;
	// cin >> root;

	// cout << root << endl;

	// top_view(root);


	//Method 2
	node_2*root = NULL;
	root = build_tree_2();

	// cout << root << endl;

	top_view_queue(root);

	return 0;
}