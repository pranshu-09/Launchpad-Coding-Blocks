// Given a 2-D array sorted along each row and each column. You need to find a particular element using staircase search

#include<iostream>
using namespace std;

string staircaseSearch(int arr[][100], int n, int key)
{
	int i=0, j=n-1;

	while(i<n and j>=0)
	{
		if(arr[i][j] == key)
			return "Yes";

		else if(arr[i][j] < key)
			i++;

		else
			j--;
	}

	return "No";
}

int main()
{
	int n, key;
	cin>>n>>key;

	int arr[100][100];

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>arr[i][j];

	cout<<staircaseSearch(arr, n, key);

	return 0;
}