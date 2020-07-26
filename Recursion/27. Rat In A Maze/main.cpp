#include <iostream>

using namespace std;

bool ratInAMaze(char path[][1001], int sol[][1001], int i, int j, int n, int m)
{
        if(i==n and j==m)
        {
                sol[i][j] = 1;
                for(int i=0;i<=n;i++)
                {
                        for(int j=0;j<=m;j++)
                        {
                                cout<<sol[i][j]<<" ";
                        }
                        cout<<endl;
                }
                return true;
        }

        if(i>n or j>m)
            return false;

        if(path[i][j] == 'X')
            return false;

        sol[i][j] = 1;

        bool rightSuccess = ratInAMaze(path, sol, i, j+1, n, m);

        if(rightSuccess)
        {
                return true;
        }
        else
        {
                bool downSuccess = ratInAMaze(path, sol, i+1, j, n, m);

                if(downSuccess)
                    return true;
                else
                {
                        sol[i][j] = 0;
                        return false;
                }
        }
}

int main()
{
    int n,m;
    cin>>n>>m;

    char path[1001][1001];

    for(int i=0;i<n;i++)
    {
            for(int j=0;j<m;j++)
            {
                    cin>>path[i][j];
            }
    }

    int sol[1001][1001] = {0};

    bool ans = ratInAMaze(path,sol, 0, 0, n-1, m-1);

    if(!ans)
    {
            cout<<-1;
    }

    return 0;
}
