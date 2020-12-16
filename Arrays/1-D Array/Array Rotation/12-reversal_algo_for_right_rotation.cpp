#include<iostream>
#include<algorithm>
using namespace std;

void reversal_algo(int arr[], int n, int k)
{
	reverse(arr, arr+n);
	reverse(arr, arr+k);
	reverse(arr+k, arr+n);
}

int main()
{
	int n;
	cin>>n;

	int arr[100];
	for(int i=0;i<n;i++)
		cin>>arr[i];

	int k;
	cin>>k;

	k = k%n;

	reversal_algo(arr, n, k);

	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";

	return 0;
}