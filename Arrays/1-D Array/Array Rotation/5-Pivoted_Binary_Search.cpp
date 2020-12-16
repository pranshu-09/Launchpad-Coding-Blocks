#include <iostream>
using namespace std;

int binary_search(int arr[], int start, int end, int key)
{
	if(end < start)
		return -1;

	int mid = (start+end)/2;

	if(arr[mid] == key)
		return mid;

	if(arr[mid] > key)
		return binary_search(arr, 0, mid-1, key);

	return binary_search(arr, mid+1, end, key);
}

int return_pivot_element(int arr[], int start, int end)
{
	if(end<start)
		return -1;

	if(end == start)
		return start;

	int mid = (start+end)/2;

	if(mid < end and arr[mid] > arr[mid+1])
		return mid;

	if(mid > start and arr[mid-1] > arr[mid])
		return mid-1;

	if(arr[mid] <= arr[start])
		return return_pivot_element(arr, start, mid-1);

	return return_pivot_element(arr, mid+1, end);
}

int pivoted_binary_search(int arr[], int n, int key)
{
	int pivot = return_pivot_element(arr, 0, n-1);

	if(pivot == -1)
		return binary_search(arr, 0, n-1, key);

	if(arr[pivot] == key)
		return pivot;

	if(key >= arr[0])
		return binary_search(arr, 0, pivot-1, key);

	else
		return binary_search(arr, pivot+1, n-1, key);
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

	cout<<pivoted_binary_search(arr, n, key);

	return 0;
}