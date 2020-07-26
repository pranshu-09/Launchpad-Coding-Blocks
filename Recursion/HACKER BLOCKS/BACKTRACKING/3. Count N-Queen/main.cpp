#include<iostream>
#include <bitset>

using namespace std;

int count=0;

bool isSafe(int board[][11], int i, int j, int n)
{
	for(int row=0;row<i;row++)
	{
		if(board[row][j]==1)
			return false;
	}

	//Left Diagonal
	int x=i;
	int y=j;

	while(x>=0 and y>=0)
	{
		if(board[x][y] == 1)
			return false;

		x--;
		y--;

	}

	//Right Diagonal
	x=i;
	y=j;

	while(x>=0 and y<n)
	{
		if(board[x][y] == 1)
		{
			return false;
		}

		x--;
		y++;
	}

	return true;
}

bool countNQueen(int board[][11], int i, int n)
{
	if(i==n)
	{
		count++;
		return false;
	}

	for(int j=0;j<n;j++)
	{
		if(isSafe(board,i,j,n))
		{
			board[i][j] = 1;

			bool restBoard = countNQueen(board, i+1, n);

			if(restBoard)
				return true;

			board[i][j] = 0;
		}
	}

	return false;
}

int count2=0;

bitset<30> col, d1, d2;

void countNQueenUsingBitset(int n, int r)
{
	if(r==n)
	{
		count2++;
		return;
	}

	for(int c=0;c<n;c++)
	{
		if(!col[c] and !d1[r-c+n-1] and !d2[r+c])
		{
			col[c] = d1[r-c+n-1] = d2[r+c] = 1;

			countNQueenUsingBitset(n, r+1);

			col[c] = d1[r-c+n-1] = d2[r+c] = 0;
		}
	}
}


int main()
{
	int n;
	cin>>n;

	int board[11][11]={0};

	// countNQueen(board, 0, n);
	// cout<<count;

	countNQueenUsingBitset(n, 0);
	cout<<count2;



	return 0;
}
