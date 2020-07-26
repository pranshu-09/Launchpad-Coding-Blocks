#include<iostream>
#include<math.h>

using namespace std;

bool isSafe(int sudoku[][9], int i, int j, int n, int num)
{
	for(int x=0;x<n;x++)
	{
		if(sudoku[x][j]==num or sudoku[i][x]==num)
			return false;
	}

	int rn = sqrt(n);
	int sx = (i/rn)*rn;
	int sy = (j/rn)*rn;

	for(int i=sx;i<sx+rn;i++)
	{
		for(int j=sy; j<sy+rn; j++)
		{
			if(sudoku[i][j]==num)
			{
				return false;
			}
		}
	}

	return true;
}

bool sudokuSolver(int sudoku[][9], int i, int j,int n)
{
	if(i==n)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<sudoku[i][j]<<" ";
			}
			cout<<endl;
		}

		return true;
	}

	if(j==n)
	{
		return sudokuSolver(sudoku, i+1, 0, n);
	}

	if(sudoku[i][j]!=0)
	{
		return sudokuSolver(sudoku, i, j+1, n);
	}

	for(int num=1;num<=9; num++)
	{
		if(isSafe(sudoku, i, j, n, num))
		{
			sudoku[i][j] = num;

			bool restSudoku = sudokuSolver(sudoku, i, j+1, n);

			if(restSudoku)
				return true;
		}

	}

	sudoku[i][j] = 0;
	return false;

}

int main()
{
	int n;
	cin>>n;

	int sudoku[9][9];

	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
			cin>>sudoku[i][j];
	}

	sudokuSolver(sudoku, 0, 0, n);

	return 0;
}
