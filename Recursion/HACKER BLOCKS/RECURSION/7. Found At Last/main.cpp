#include<iostream>

using namespace std;

int lastIndexFound(long long int arr[], int si, int n, long long int key)
{
	if(si == n)
		return -1;

	int lastIndex = lastIndexFound(arr, si+1, n, key);

	if(lastIndex == -1)
	{
		if(arr[si] == key)
			return si;
		else
			return -1;
	}
	else
		return lastIndex;
}

int main()
{
	int n;
	cin>>n;

	long long int arr[n];

	for(int i=0;i<n;i++)
		cin>>arr[i];

	long long int key;
	cin>>key;

	cout<<lastIndexFound(arr,0,n,key);

	return 0;
}
