#include<iostream>
using namespace std;

int clear_range(int n, int i, int j){
	// Mask
	int mask1 = (-1 << j+1);
	int mask2 = (1 << i) - 1;

	int mask = mask1 | mask2;

	int ans = n & mask;

	return ans;
}

int replace_n_by_m(int n, int m, int i, int j){

	// Clear bits in the the range [i, j]
	int cleared_n = clear_range(n, i, j);

	int mask = m<<i;

	int ans = cleared_n | mask;

	return ans;
}

int main(){

	int n, m;
	cin>>n>>m;

	int i, j;
	cin>>i>>j;

	cout<<replace_n_by_m(n, m, i, j)<<endl;


	return 0;
}	