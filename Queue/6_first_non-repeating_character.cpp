#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

int main() {

	char ch;
	cin >> ch;

	queue<char> q;
	unordered_map<char, int> freq;

	while (ch != '.') {

		freq[ch]++;
		q.push(ch);

		if (freq[q.front()] == 1) {
			cout << q.front() << endl;
		}
		else {
			while (freq[q.front()] > 1) {
				q.pop();
			}

			if (q.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << q.front() << endl;
			}
		}

		cin >> ch;
	}

	return 0;
}
