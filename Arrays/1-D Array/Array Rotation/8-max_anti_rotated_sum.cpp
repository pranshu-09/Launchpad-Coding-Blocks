#include<iostream>
#include<climits>
using namespace std;

// Approach 1 - O(N^2)
int maxmimum_rotated_sum1(int arr[], int n)
{
	int max_sum = INT_MIN;

	for(int i=0;i<n;i++)
	{
		int curr_sum = 0;
		for(int j=0;j<n;j++)
		{
			int idx = (i+j)%n;

			curr_sum += j*arr[idx];
		}

		max_sum = max(max_sum, curr_sum);  
	}

	return max_sum;
}


// Approach 2 - O(N)
int maxmimum_rotated_sum2(int arr[], int n)
{
	int arr_sum=0, curr_sum=0;

	for(int i=0;i<n;i++)
	{
		arr_sum += arr[i];
		curr_sum += i*arr[i];
	}

	int max_sum = 0;

	for(int j=1;j<n;j++)
	{
		curr_sum = curr_sum - (arr_sum - (n)*arr[j-1]);

		max_sum = max(max_sum, curr_sum);
	}

	return max_sum;
}


// Approach 3 - O(N) - Approach can only be used if array is sorted or maxmimum_rotated_sum2
int return_pivot(int arr[], int n)
{
	for(int i=0;i<n;i++)
	{
		if(arr[i] > arr[(i+1)%n])
			return i;
	}
}

int maxmimum_rotated_sum3(int arr[], int n)
{
	int sum=0;
	int pivot = return_pivot(arr, n);

	int diff = n - 1 - pivot;

	for(int i=0;i<n;i++)
	{
		sum = sum + ((i+diff)%n) * arr[i];
	}

	return sum;
}



int main()
{
	int n;
	cin>>n;

	int arr[100];

	for(int i=0;i<n;i++)
		cin>>arr[i];

	cout<<maxmimum_rotated_sum3(arr, n);

	return 0;

}