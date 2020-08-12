#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;

	int arr[1000];

	for(int i=0;i<n;i++)
		cin>>arr[i];

	int max_Sum=0, curr_Sum=0;
	int left = -1, right = -1;

	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			curr_Sum = 0;

			for(int k=i; k<=j; k++)
			{
				curr_Sum += arr[k];
			}

			// Updating maximum sum if curr_sum > max_sum

			if(curr_Sum > max_Sum)
			{
				max_Sum = curr_Sum; 
				left = i;
				right = j;
			}
		}
	}

	cout<<"Maximum subarray sum is "<<max_Sum<<endl;

	cout<<"Subarray with maximum sum :"<<endl;

	for(int i=left; i<=right; i++)
		cout<<arr[i]<<" ";

	cout<<endl;


	return 0;
}