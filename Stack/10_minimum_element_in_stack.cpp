#include<iostream>
#include<stack>
#include<climits>

using namespace std;

int main() {

	int n;
	cin >> n;

	stack<int> s;
	int curr_min = 0;

	while (n != -1) {

		// To insert in stack
		if (n == 1) {

			int elem;
			cin >> elem;

			if (s.empty() or elem >= curr_min) {

				if (s.empty())
					curr_min = elem;

				s.push(elem);
			}
			else {
				int l = (2 * elem - curr_min);
				curr_min = elem;
				s.push(l);
			}
		}

		// To delete element from stack
		else if (n == 2) {

			if (s.empty())
				cout << "Stack is Empty" << endl;
			else {
				if (s.top() >= curr_min) {
					s.pop();
				}
				else {
					curr_min = (2 * curr_min - s.top());
					s.pop();
				}
			}

		}

		// To get the minimum element in stack
		else if (n == 3) {
			cout << curr_min << endl;
		}

		cin >> n;
	}

	return 0;
}