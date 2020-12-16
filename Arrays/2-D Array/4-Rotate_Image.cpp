#include<iostream>
#include<algorithm>
using namespace std;

void rotateImage(int arr[1000][1000], int n)
{
	for(int i=0;i<n;i++)
	{
		int start = 0;
		int end = n-1;

		while(start<end)
		{
			swap(arr[i][start], arr[i][end]);
			start++;
			end--;
		}
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			swap(arr[i][j], arr[j][i]);
		}
	}

	for(int i=0;i<n;i++)
	{	for(int j=0;j<n;j++)
			cout<<arr[i][j]<<" ";
		cout<<endl;
	}
}

void rotateSTL(int arr[][1000], int n)
{
	for(int i=0;i<n;i++)
		reverse(arr[i], arr[i]+n);

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			swap(arr[i][j], arr[j][i]);
		}
	}

	for(int i=0;i<n;i++)
	{	for(int j=0;j<n;j++)
			cout<<arr[i][j]<<" ";
		cout<<endl;
	}

}

int main()
{

	int n;
	cin>>n;

	int arr[1000][1000];

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>arr[i][j];

	// rotateImage(arr, n);

	rotateSTL(arr, n);

	return 0;
}