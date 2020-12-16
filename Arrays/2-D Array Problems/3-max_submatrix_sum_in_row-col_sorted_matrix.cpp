#include<iostream>
#include<climits>
using namespace std;

// We will make suffix sum matrix in this question

int maximum_submatrix_sum(int arr[][10], int n, int m)
{
	//Column Wise Addition
	for(int i=n-1;i>=0;i--)
		for(int j=m-2;j>=0;j--)
			arr[i][j] += arr[i][j+1];

	//Row Wise Additon
	for(int j=m-1;j>=0;j--)
		for(int i=n-2;i>=0;i--)
			arr[i][j] += arr[i+1][j] ;

	int result = INT_MIN;

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			result = max(result, arr[i][j]);

	return result;
}

int main()
{	
	int n,m;
	cin>>n>>m;

	int arr[10][10];

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>arr[i][j];

	cout<<maximum_submatrix_sum(arr, n, m);

	return 0;
}