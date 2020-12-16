#include<iostream>
#include<algorithm>
using namespace std;

void rotate_array(int arr[], int n)
{
	int x = arr[n-1];

	for(int i=n-1;i>=0;i--)
	{
		arr[i] = arr[i-1];
 	}

 	arr[0] = x;

 	for(int i=0;i<n;i++)
 		cout<<arr[i]<<" ";
}

void rotate_array_using_reverse(int arr[], int n)
{
	reverse(arr, arr+n-1);
	reverse(arr, arr+n);

	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
}

int main()
{
	int n;
	cin>>n;

	int arr[100];

	for(int i=0;i<n;i++)
		cin>>arr[i];

	// rotate_array(arr, n);

	rotate_array_using_reverse(arr, n);

	return 0;
}