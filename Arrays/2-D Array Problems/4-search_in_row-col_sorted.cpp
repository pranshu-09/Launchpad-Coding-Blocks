#include<iostream>
using namespace std;

bool element_found(int arr[][10], int n, int m, int key)
{
	int x = 0;
	int y = m-1;

	while(y>=0 and x<=n-1)
	{
		if(key == arr[x][y])
			return true;

		else if(key > arr[x][y])
			x++;

		else
			y--;
	}

	return false;
}

int main()
{
	int n, m;
	cin>>n>>m;

	int arr[10][10];

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>arr[i][j];

	int key;
	cin>>key;

	cout<<element_found(arr, n, m, key);

	return 0;
}