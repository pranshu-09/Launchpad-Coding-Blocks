#include<iostream>
using namespace std;

int min_element(int arr[], int low, int high)
{
	if(high < low)
		return -1;

	if(high == low)
		return low;

	int mid = (low+high)/2;

	if(mid < high and arr[mid] > arr[mid+1])
		return mid+1;

	if(mid > low and arr[mid-1] > arr[mid])
		return mid;

	if(arr[mid] <= arr[low])
		return min_element(arr, low, mid-1);

	return min_element(arr, mid+1, high);
}

int main()
{
	int n;
	cin>>n;

	int arr[100];
	for(int i=0;i<n;i++)
		cin>>arr[i];

	int min_idx = min_element(arr, 0, n-1);

	cout<<min_idx<<endl;

	cout<<arr[min_idx]<<endl;

	return 0;
}