#include<iostream>
using namespace std;

int unique_number_3(int arr[], int n){

	int bits[64] = {0};

	for(int i=0;i<n;i++){

		int pos=0, temp = arr[i];

		while(temp > 0){

			bits[pos] += temp&1;
			temp >>= 1;
			pos++;
		}
	}

	int ans=0, p=1;

	for(int i=0;i<64;i++){

		bits[i] = bits[i]%3;

		ans = ans + bits[i]*p;
		p = p*2;

	}


	return ans;
}

int main(){

	int n;
	cin>>n;

	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];

	cout<<unique_number_3(arr, n);

	return 0;
}