#include<iostream>
using namespace std;

void swap_elements(int arr[], int first_idx, int second_idx, int d)
{
	for(int i=0;i<d;i++)
	{
		swap(arr[first_idx + i], arr[second_idx + i]);
	}
}

void block_swap_algorithm(int arr[], int n, int d)
{
	if(d==0 or d==n)
		return;

	if(n-d == d)
	{
		swap_elements(arr, 0, d, d);		// If elements to be swapped are exactly half of the size of the array
		return;
	}

	if(d < n-d)
	{
		swap_elements(arr, 0, n-d, d);
		block_swap_algorithm(arr, n-d, d);
	}

	else
	{
		swap_elements(arr, 0, d, n-d);
		block_swap_algorithm(arr+n-d, n-(n-d), d-(n-d));
	}
}

void print(int arr[], int n)
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
}

int main()
{
	int n, d;
	cin>>n>>d;

	d = d % n;

	int arr[100];

	for(int i=0;i<n;i++)
		cin>>arr[i];

	block_swap_algorithm(arr, n, d);
	print(arr, n);

}