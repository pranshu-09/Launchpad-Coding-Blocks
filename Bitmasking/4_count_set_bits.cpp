#include <iostream>
using namespace std;

// Method 1
int count_set_bits(int N){

	int ans=0;

	while(N>0){

		int bit = N&1;
		ans += bit;
		N >>= 1;
	}

	return ans;
}


// Method 2
int count_set_bits_fast(int n){

	int ans=0;

	while(n>0){
		n = (n & n-1);
		ans++;
	}

	return ans;
}

int main(){

	int n;
	cin>>n;

	cout<<count_set_bits(n)<<endl;
	cout<<count_set_bits_fast(n)<<endl;
	cout<<__builtin_popcount(n)<<endl;

	return 0;
}