#include<iostream>
using namespace std;

void printIndices(int arr[], int si, int n, int key)
{
	if(si==n)
		return;

	if(arr[si] == key)
		cout<<si<<" ";

	printIndices(arr, si+1, n, key);

}

int main()
{
	int n;
	cin>>n;

	int arr[n];

	for(int i=0;i<n;i++)
		cin>>arr[i];

	int key;
	cin>>key;


	printIndices(arr,0,n,key);
	return 0;
}
