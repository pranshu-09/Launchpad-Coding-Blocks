#include<iostream>
using namespace std;

bool sortedArray(int arr[], int si, int n)
{
	if(si == n-1)
		return true;

	if(arr[si] <= arr[si+1] and sortedArray(arr, si+1, n))
		return true;

	return false;
}

int main()
{
	int n;
	cin>>n;

	int arr[n];

	for(int i=0;i<n;i++)
		cin>>arr[i];

	bool res = sortedArray(arr,0,n);

	if(res)
		cout<<"true";
	else
		cout<<"false";

	return 0;
}
