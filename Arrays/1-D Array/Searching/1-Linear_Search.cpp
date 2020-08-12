#include<iostream>
using namespace std;

int linearSearch(int n, int arr[], int key)
{
	for(int i=0;i<n;i++)
	{
		if(arr[i] == key)
			return i;
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

	cout<<linearSearch(n, arr, key)<<endl;

	return 0;
}