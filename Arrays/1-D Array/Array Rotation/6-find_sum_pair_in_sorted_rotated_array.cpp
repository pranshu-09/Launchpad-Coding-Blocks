#include<iostream>
using namespace std;

// Check if sum pair is present in the array or not
bool sum_pair_possible(int arr[], int n, int sum_pair)
{
	int i;

	//To find the pivot element
	for(i=0;i<n-1;i++)
	{
		if(arr[i] > arr[i+1])
			break;
	}

	int low = (i+1)%n;		// The next element to the pivot element will be smallest element of the array
	int high = i;

	while(low != high)
	{
		int sum = arr[low] + arr[high];

		if(sum_pair == sum)
			return true;

		else if(sum_pair > sum)
			low = (low+1)%n;		// Rotational movement in array

		else
			high = (n + high - 1)%n;		// So that high do not go below 0
	}

	return false;
}



// Count the no. of sum pairs
int count_sum_pairs(int arr[], int n, int sum_pair)
{
	int i;

	for(i=0;i<n-1;i++)
		if(arr[i] > arr[i+1])
			break;

	int high = i;
	int low = (i+1)%n;

	int count=0;

	while(low != high)
	{
		int sum = arr[low] + arr[high];

		if(sum == sum_pair)
		{
			count++;

			if(low == (n + high - 1)%n)
				return count;

			low = (low + 1)%n;
			high = (high - 1 + n)%n;
		}

		else if(sum_pair > sum)
			low = (low+1)%n;

		else
			high = (high-1+n)%n;
	}

	return count;
}

int main()
{
	int n;
	cin>>n;

	int arr[100];

	for(int i=0;i<n;i++)
		cin>>arr[i];

	int sum_pair;
	cin>>sum_pair;

	cout<<sum_pair_possible(arr, n, sum_pair)<<endl;

	cout<<count_sum_pairs(arr, n, sum_pair);

	return 0;
}