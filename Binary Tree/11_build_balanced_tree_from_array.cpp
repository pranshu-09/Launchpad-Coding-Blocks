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

node*build_balanced_tree(int arr[], int start, int end) {

	if (start > end) {
		return NULL;
	}

	int mid = (start + end) / 2;

	node*root = new node(arr[mid]);
	root->left = build_balanced_tree(arr, start, mid - 1);
	root->right = build_balanced_tree(arr, mid + 1, end);

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

			if (f->left != NULL) {
				q.push(f->left);
			}

			if (f->right != NULL) {
				q.push(f->right);
			}
		}
	}

}

int main() {

	int n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	node*root = build_balanced_tree(arr, 0, n - 1);

	bfs_print(root);

	return 0;
}