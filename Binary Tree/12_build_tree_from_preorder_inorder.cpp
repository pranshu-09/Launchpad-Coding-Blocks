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


node*build_tree_from_pre_and_in(int pre[], int in[], int start, int end) {

	static int i = 0;		// Static Pointer variable to travere preorder array

	if (start > end) {
		return NULL;
	}

	node*root = new node(pre[i]);

	int index = -1;

	for (int j = start; j <= end; j++) {
		if (in[j] == pre[i]) {
			index = j;
			break;
		}
	}

	i++;

	root->left = build_tree_from_pre_and_in(pre, in, start, index - 1);
	root->right = build_tree_from_pre_and_in(pre, in, index + 1, end);

	return root;
}

void bfs_print(node*root) {

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

			if (f->left) {
				q.push(f->left);
			}

			if (f->right) {
				q.push(f->right);
			}
		}
	}
}

int main() {

	int n;
	cin >> n;

	int pre[n];
	for (int i = 0; i < n; i++)
		cin >> pre[i];

	int in[n];
	for (int i = 0; i < n; i++)
		cin >> in[i];

	node*root = build_tree_from_pre_and_in(pre, in, 0, n - 1);

	bfs_print(root);

	return 0;
}