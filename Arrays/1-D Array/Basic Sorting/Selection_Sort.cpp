#include<iostream>
using namespace std;

void selectionSort(int n, int arr[])
{
	for(int i=0;i<n-1;i++)
	{
		int min_idx = i;

		for (int j = i; j <= n-1; j++)
		{
			if(arr[j] < arr[min_idx])
				min_idx = j;
		}

		swap(arr[i], arr[min_idx]);
	}
}

int main()
{
	int n;
	cin>>n;

	int arr[n];

	for(int i=0;i<n;i++)
		cin>>arr[i];

	selectionSort(n, arr);

	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";

	cout<<endl;

	return 0;
}