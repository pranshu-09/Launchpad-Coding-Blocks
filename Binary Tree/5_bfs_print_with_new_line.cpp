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

	if (d == -1)
		return NULL;

	node*root = new node(d);
	root->left = build_tree();
	root->right = build_tree();

	return root;
}

void bfs_traversal_1(node*root) {

	queue<pair<node*, int> > q;

	int level = 0;

	q.push({root, 0});

	while (!q.empty()) {

		auto f = q.front();

		if (f.second == level) {
			cout << f.first->data << " ";
		}
		else {
			cout << endl;
			cout << f.first->data << " ";
			level++;
		}

		q.pop();

		if (f.first->left != NULL) {
			q.push({f.first->left, f.second + 1});
		}

		if (f.first->right != NULL) {
			q.push({f.first->right, f.second + 1});
		}
	}
}


void bfs_traversal_2(node*root) {

	queue<node*>q;

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

			if (f->left != NULL) {
				q.push(f->left);
			}

			if (f->right != NULL) {
				q.push(f->right);
			}
		}
	}
}


int main()
{
	node*root = build_tree();

	bfs_traversal_2(root);

	return 0;
}