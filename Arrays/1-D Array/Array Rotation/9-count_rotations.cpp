#include<iostream>
using namespace std;

// Approach 1 - O(N)... Use linear search to find idx of smallest element
int count_rotations_linear(int arr[], int n)
{
	int idx = 0, small = arr[0];

	for(int i=1;i<n;i++)
	{
		if(arr[i]< small)
		{
			small = arr[i];
			idx = i;
		}
	}

	return idx;
} 


// Approach 1 - O(N)... Use linear search to find idx of smallest element
int count_rotations_binary(int arr[], int low, int high)
{
	if(high < low)
		return -1;

	if(high == low)
		return low;

	int mid = (low+high)/2;

	if(mid < high and arr[mid] > arr[mid+1])
		return (mid+1);							// We need element next to pivot element as it would be the smallest

	if(mid > low and arr[mid-1] > arr[mid])
		return mid;

	if(arr[mid] <= arr[low])
		return count_rotations_binary(arr, low, mid-1);

	return count_rotations_binary(arr, mid+1, high);
}


int main()
{
	int n;
	cin>>n;

	int arr[100];

	for(int i=0;i<n;i++)
		cin>>arr[i];

	cout<<count_rotations_binary(arr, 0, n-1);
}