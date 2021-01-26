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


// Maximum Path Sum

class Pair {

public:
	int branch_sum;
	int max_sum;

	Pair() {
		branch_sum = 0;
		max_sum = 0;
	}
};


Pair max_path_sum(node*root) {

	Pair p;

	if (root == NULL) {
		return p;				// p.branch_sum and p.max_sum would both be 0 if root == NULL
	}

	Pair left_sums = max_path_sum(root->left);
	Pair right_sums = max_path_sum(root->right);


	// Finding current sum including the root node
	int op1 = root->data;
	int op2 = root->data + left_sums.branch_sum;
	int op3 = root->data + right_sums.branch_sum;
	int op4 = left_sums.branch_sum + root->data + right_sums.branch_sum;

	int curr_sum_with_node = max(op1, max(op2, max(op3, op4)));


	// Finding the current node's branch sum
	p.branch_sum = max(left_sums.branch_sum, max(right_sums.branch_sum, 0)) + root->data;

	// Finding the current node's maximum sum
	p.max_sum = max(left_sums.max_sum, max(right_sums.max_sum, curr_sum_with_node));

	return p;
}


int main() {

	node*root = build_tree();

	bfs_print(root);

	Pair ans = max_path_sum(root);

	cout << "Maximum Path Sum of the tree is " << ans.max_sum << endl;

	return 0;
}