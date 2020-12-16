#include<iostream>
using namespace std;

int submatrix_sum_II(int arr[][10], int n, int m)
{
	//Generating a Prefix Sum Matrix
	int prefix_sum[n][m]={0};

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			prefix_sum[i][j] = 0;
	}

	for(int ti=0;ti<n;ti++)
	{
		for(int tj=0;tj<m;tj++)
		{
			for(int i=0;i<=ti;i++)
			{
				for(int j=0;j<=tj;j++)
				{
					prefix_sum[ti][tj] += arr[i][j];
				}
			}
		}
	}

	int sum=0;

	// Finding sum of all submatrix
	for(int ti=1;ti<n;ti++){
		for(int tj=1;tj<m;tj++){

			// if(ti==0 and tj==0)
			// 	continue;

			for(int i=ti;i<n;i++){
				for(int j=tj;j<m;j++){

					sum = sum + (prefix_sum[i][j] - prefix_sum[ti-1][j] - prefix_sum[i][tj-1] + prefix_sum[ti-1][tj-1]);
				}
			}
		}
	}

	return sum;

}

int submatrix_sum_II(int arr[][10], int n, int m)
{
	// Prefix Sum Matrix

	// Adding columns elements
	for(int i=0;i<n;i++)
		for(int j=1;j<m;j++)
			arr[i][j] += arr[i][j-1];

	// Adding row elements
	for(int j=0;j<m;j++)
		for(int i=1;i<n;i++)
			arr[i][j] += arr[i-1][j];

	int sum=0;

	for(int )

}

int submatrix_sum_III(int arr[][10], int n, int m)
{
	int sum = 0;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int tl = ((i+1)*(j+1));
			int br = ((n-i)*(m-j));
			sum += (tl*br) * arr[i][j];
		}
	}

	return sum;
}


int main()
{
	int n, m;
	cin>>n>>m;

	int arr[10][10];

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>arr[i][j];


	cout<<submatrix_sum_III(arr, n, m);

	return 0;
}