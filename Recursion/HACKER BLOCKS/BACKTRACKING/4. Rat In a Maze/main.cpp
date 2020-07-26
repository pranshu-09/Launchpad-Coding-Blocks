#include<iostream>
using namespace std;

bool printRatInAMaze(char maze[][1001], int sol[][1001], int sr, int sc, int er, int ec)
{
	if(sr==er and sc==ec)
	{
		sol[sr][sc] = 1;

		for(int i=0;i<=er;i++)
		{
			for(int j=0;j<=ec;j++)
			{
				cout<<sol[i][j]<<" ";
			}
			cout<<endl;
		}
		return true;
	}

	if(sr>er or sc>ec)
		return false;

	if(maze[sr][sc]=='X')
		return false;

	sol[sr][sc] = 1;

	bool rightSuccess = printRatInAMaze(maze, sol, sr, sc+1, er, ec);

	if(rightSuccess)
	{
		return true;
	}
	else
	{
		bool downSuccess = printRatInAMaze(maze, sol, sr+1, sc, er, ec);

		if(downSuccess)
			return true;
		else
		{
			sol[sr][sc] = 0;
			return false;
		}
	}
}

int main()
{
	int n,m;
	cin>>n>>m;

	char maze[1001][1001];

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>maze[i][j];
		}
	}

	int sol[1001][1001] = {0};

	bool res = printRatInAMaze(maze, sol, 0,0, n-1, m-1);

	if(!res)
	{
		cout<<-1;
	}

	return 0;
}
