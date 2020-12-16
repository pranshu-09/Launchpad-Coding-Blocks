#include<iostream>
using namespace std;

// This approach will work fine for 4x4 matrix. However, it might fail wiht matrix of other sizes. This happens because of the final row print or final column
// print. We can fix them by adding the condition that if (sr<er), then only print the final row. Also, if(sc<ec), then only print the final column.

void spiralPrint(int arr[][100], int n, int m)
{
	int sr=0, sc=0, er=n-1, ec=m-1;

	while(sr<=er and sc<=ec)
	{
		for(int i=sc; i<=ec; i++)
			cout<<arr[sr][i]<<" ";
		sr++;

		for(int i=sr; i<=er; i++)
			cout<<arr[i][ec]<<" ";
		ec--;

		if(sr<er)
		{	
			for(int i=ec; i>=sc; i--)
				cout<<arr[er][i]<<" ";
			er--;
		}

		if(sc<ec)
		{	
			for(int i=er; i>=sr; i--)
				cout<<arr[i][sc]<<" "; 
			sc++;
		}
	}
}


int main()
{
	int n, m;
	cin>>n>>m;

	int arr[100][100];

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>arr[i][j];

	spiralPrint(arr, n, m);

	return 0;
}