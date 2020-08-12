// Maximum Subarray Sum - O(N2)

#include<iostream>
#include<climits>
using namespace std;

int main()
{
	int n;
	cin>>n;

	int arr[1000];

	for(int i=0;i<n;i++)
		cin>>arr[i];

	// Approach 1

	int c_sum[1000] = {0};

	c_sum[0] = arr[0];

	for(int i=1;i<n;i++) 
	{
		c_sum[i] = c_sum[i-1] + arr[i];
	}

	int currSum=0, maxSum = 0;
	int left = -1, right = -1;

	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			currSum = 0;
			currSum = c_sum[j] - c_sum[i-1];

			if(currSum > maxSum)
			{
				maxSum = currSum;
				left = i;
				right = j;
			}
		}
	}

	cout<<"Maximum sum of a subarray : "<<maxSum<<endl;
	cout<<"Corresponding Subarray : "<<endl;

	for (int i = left; i <= right; ++i)
	{
		cout<<arr[i]<<" ";
	}

	cout<<endl;


	// Approach 2 

	int max_sum = INT_MIN;

	for(int i=0;i<n;i++)
	{
		int sum = 0;
		
		for(int j=i;j<n;j++)
		{
			sum += arr[j];

			if(sum > max_sum)
				max_sum = sum;
		}
	}

	cout<<"Maximum sum of a subarray : "<<max_sum<<endl;

	return 0;

}