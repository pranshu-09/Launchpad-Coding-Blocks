#include<iostream>
#include<set>
using namespace std;

int main() {

	set<pair<int, int> > s;

	s.insert(make_pair(10, 11));
	s.insert(make_pair(10, 15));
	s.insert(make_pair(5, 50));
	s.insert(make_pair(1, 11));
	s.insert(make_pair(5, 22));

	for (auto p : s) {
		cout << p.first << " " << p.second << endl;
	}

	// Lower Bound
	auto lb = s.lower_bound(make_pair(5, 50));
	cout << endl << "Lower Bound -> " << lb->first << " " << lb->second << endl;

	// Upper Bound
	auto ub = s.upper_bound(make_pair(10, 11));
	cout << endl << "Upper Bound -> " << ub->first << " " << ub->second << endl;

	return 0;
}