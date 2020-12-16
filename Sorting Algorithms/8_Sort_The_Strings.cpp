#include<iostream>
#include<cstring>
#include <algorithm>
using namespace std;

string get_token_from_the_key(string s, int key) {

	char*res = strtok((char*)s.c_str(), " ");

	while (key > 1) {
		res = strtok(NULL, " ");
		key--;
	}

	return res;
}

int convert_to_int(string s) {

	int ans = 0;
	int p = 1;

	for (int i = s.length() - 1; i >= 0 ; i--) {
		int no = s[i] - '0';
		ans += (no * p);

		p = p * 10;
	}

	return ans;
}

bool numeric_sort(pair<string, string> a, pair<string, string> b) {
	string key1 = a.second;
	string key2 = b.second;

	return convert_to_int(key1) < convert_to_int(key2);
}

bool lexico_sort(pair<string, string> a, pair<string, string> b) {

	string key1 = a.second;
	string key2 = b.second;

	return key1 < key2;
}

int main() {

	int n;
	cin >> n;

	cin.get();

	string s[100];

	for (int i = 0; i < n; i++)
		getline(cin, s[i]);

	int key;
	string reversal, ordering;
	cin >> key >> reversal >> ordering;

	pair<string, string > p[100];

	for (int i = 0; i < n; i++) {
		p[i].first = s[i];
		p[i].second = get_token_from_the_key(s[i], key);
	}

	if (ordering == "numeric") {
		sort(p, p + n, numeric_sort);
	}
	else {
		sort(p, p + n, lexico_sort);
	}


	if (reversal == "true") {
		reverse(p, p + n);
	}


	for (auto x : p) {
		cout << x.first << endl;
	}

	return 0;
}