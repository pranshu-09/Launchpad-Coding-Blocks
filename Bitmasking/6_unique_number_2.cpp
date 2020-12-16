#include<iostream>
using namespace std;

void unique_number_2(int arr[], int n){

	int res = 0;

	for(int i=0;i<n;i++)
		res = res ^ arr[i];			// res will have the xor of the 2 unique numbers.

	int temp = res;

	int pos = 0, i=0;

	while(temp>0){
		if(temp & 1){	
			pos = i;
			break;
		}
		temp = temp>>1;
		i++;
	}

	int a=0; 						// First unique number

	for(int i=0;i<n;i++){

		if(arr[i] & (1<<pos))
			a = a^arr[i];
	}

	int b = res ^ a;

	cout<<"Unique Numbers are "<<a<<" and "<<b;

}

int main(){

	int n;
	cin>>n;

	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];

	unique_number_2(arr, n);

	return 0;
}