#include<iostream>
using namespace std;
 
void insertionSort(int n, int arr[])
{
	for(int i=1;i<n;i++)
	{
		int j=i-1;
		int temp = arr[i];

		while(j>=0 and temp < arr[j])
		{
			arr[j+1] = arr[j];
			j--;
		}

		arr[j+1] = temp;
	}
}

int main()
{
	int n;
	cin>>n;

	int arr[n];

	for(int i=0;i<n;i++)
		cin>>arr[i];

	insertionSort(n, arr);

	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";

	cout<<endl;

	return 0;
}