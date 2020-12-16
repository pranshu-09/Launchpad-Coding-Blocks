#include <iostream>
using namespace std;

int dec_to_bin(int n){

	int ans=0, p=1;

	while(n > 0){
		int last_bit = n&1;
		ans = ans + last_bit*p;

		p = p*10;
		n = n>>1;
	}

	return ans;
}

int main(){

	int n;
	cin>>n;

	cout<<dec_to_bin(n);

	return 0;
}
