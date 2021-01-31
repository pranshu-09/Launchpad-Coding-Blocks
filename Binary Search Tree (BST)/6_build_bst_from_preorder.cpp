#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
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


node*build_from_pre(vector<int>pre, vector<int> in, int start, int end) {

	static int i = 0;

	if (start > end) {
		return NULL;
	}

	node*root = new node(pre[i]);

	int idx = -1;
	for (int x = start; x <= end; x++) {
		if (in[x] == pre[i]) {
			idx = x;
			break;
		}
	}

	i++;

	root->left = build_from_pre(pre, in, start, idx - 1);
	root->right = build_from_pre(pre, in, idx + 1, end);

	return root;
}

void inorder(node*root) {
	if (root == NULL) return;

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
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

			if (f->left)
				q.push(f->left);

			if (f->right)
				q.push(f->right);
		}
	}
}

int main() {

	int n;
	cin >> n;

	vector<int> pre;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		pre.push_back(x);
	}

	vector<int> in(pre);
	sort(in.begin(), in.end());

	node*root = build_from_pre(pre, in, 0, n - 1);

	bfs_print(root);
	cout << endl;

	inorder(root);

	return 	0;
}