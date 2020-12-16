#include<iostream>
using namespace std;

void leftrotate(int temp[], int n, int k)
{
	int start = k%n;

	for(int i = start; i < start+n; ++i)
	{
		cout<<temp[i]<<" ";		
	}
}

void leftrotate_space_efficient(int arr[], int n, int k)
{
	for(int i=k; i<k+n;i++)
		cout<<arr[i%n]<<" ";
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

	// This approach uses extra space to create temp.  Time Complexity - O(N) to print the array 
	// int temp[2*n];

	// for(int i=0;i<n;i++)
	// 	temp[i] = temp[n+i] = arr[i];

	// leftrotate(temp, n, k);

	leftrotate_space_efficient(arr, n, k);

	return 0;
}