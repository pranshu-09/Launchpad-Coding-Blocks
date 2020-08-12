#include<iostream>
using namespace std;

bool compare(int a, int b)
{
	cout<<"Comparing "<<a<<" and "<<b<<endl;
	return a > b;
}

void bubbleSort(int n, int arr[], bool (&cmp)(int a, int b))  // This is how we accept another function as a parameter of a function
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0; j<n-i-1;j++)
		{
			if(cmp(arr[j], arr[j+1]))
			{
				swap(arr[j], arr[j+1]);
			}
		}
	}
}

int main()
{
	int n;
	cin>>n;

	int arr[n];

	for(int i=0;i<n;i++)
		cin>>arr[i];

	bubbleSort(n, arr, compare);

	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";

	cout<<endl;

	return 0;
}