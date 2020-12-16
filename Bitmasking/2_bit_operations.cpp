#include<iostream>
using namespace std;

bool isOdd(int n){
	return n&1;
}

int get_bit(int n, int i){
	int mask = (1<<i);

	int bit = (n & (mask)) ? 1 : 0;

	return bit;
}

int set_bit(int n, int i){
	int mask = (1<<i);
	int ans = (n | mask);
	return ans;
}

int clear_bit(int n, int i){
	int mask = ~(1<<i);
	int ans = (n & mask);
	return ans;	
}

int update_bit(int n, int i, int v){

	//Clear bit at i
	int mask = ~(1<<i);
	int cleared_n = (n & mask);

	// Update bit
	int ans = (cleared_n | (v<<i));

	return ans;
}

int clear_last_i_bits(int n, int i){

	//Mask
	int mask = (-1<<i);

	int ans = n & mask;

	return ans;
}

int clear_range_of_bit(int n, int i, int j){

	// Mask
	int mask1 = (-1 << j+1);
	int mask2 = (1 << i) - 1;

	int mask = mask1 | mask2;

	int ans = n & mask;
	return ans;
}

int main(){

	// int n;
	// cin>>n;

	// cout<<isOdd(n)<<endl;

	int n, i;
	cin>>n>>i;

	// cout<<get_bit(n, i)<<endl;

	// cout<<set_bit(n, i)<<endl;

	// cout<<clear_bit(n, i)<<endl;

	// int v;
	// cin>>v;
	// cout<<update_bit(n, i, v)<<endl;

	// cout<<clear_last_i_bits(n, i)<<endl;

	int j;
	cin>>j;
	cout<<clear_range_of_bit(n, i, j)<<endl;

	return 0;
}