#include<iostream>
using namespace std;

int maxmimum_rotated_sum(int arr[], int n)
{
	int arr_sum = 0;
	int curr_sum = 0;

	for(int i=0;i<n;i++)
	{
		arr_sum += arr[i];
		curr_sum += (i*arr[i]); 
	}

	int max_sum = curr_sum;

	for(int j=1;j<n;j++)
	{
		curr_sum = curr_sum + (arr_sum - n*(arr[n-j]));

		if(curr_sum > max_sum)
			max_sum = curr_sum;
	}

	return max_sum;
}

int main()
{
	int n;
	cin>>n;

	int arr[100];

	for(int i=0;i<n;i++)
		cin>>arr[i];

	cout<<maxmimum_rotated_sum(arr, n);

	return 0;

}