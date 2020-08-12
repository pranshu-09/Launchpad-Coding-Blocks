// Maximum Subarray Sum - O(N)

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

	// Kadane's Algorithm

	// int currSum=0, maxSum=0;

	// for(int i=0;i<n;i++)
	// {
	// 	currSum += arr[i];

	// 	if(currSum > maxSum)
	// 		maxSum = currSum;

	// 	if(currSum < 0)
	// 		currSum = 0;
	// }

	// cout<<"Maximum sum of a subarray : "<<maxSum<<endl;


	// Another Approach

	int currSum = arr[0], maxSum = arr[0];

	for(int i=1;i<n;i++)
	{
		currSum = max(currSum + arr[i], arr[i]);
		maxSum = max(currSum, maxSum);
	}

	cout<<"Maximum sum of a subarray : "<<maxSum<<endl;

	return 0;

}