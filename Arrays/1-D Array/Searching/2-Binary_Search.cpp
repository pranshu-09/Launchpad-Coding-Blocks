#include<iostream>
using namespace std;

int binarySearch(int n, int arr[], int key)
{
	int start=0, end=n-1;

	while(start<=end)
	{
		int  mid = (start+end)/2;

		if(key == arr[mid])
			return mid;
		else if(key < arr[mid])
			end = mid-1;
		else
			start = mid+1;
	}
	return -1;
}

int main()
{
	int n;
	cin>>n;

	int arr[100];

	for(int i=0;i<n;i++)
		cin>>arr[i];

	int key;
	cin>>key;

	cout<<binarySearch(n, arr, key)<<endl<<endl;

	return 0;
}