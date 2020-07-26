#include <iostream>

using namespace std;

int count = 0;

bool ratInAMaze(char path[][100], int sol[][100], int i, int j, int n, int m)
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
                cout<<endl;
                count++;

                return true;
        }

        if(i>n or j>m)
            return false;

        if(path[i][j] == 'X')
            return false;

        sol[i][j] = 1;

        bool rightSuccess = ratInAMaze(path, sol, i, j+1, n, m);
        bool downSuccess = ratInAMaze(path, sol, i+1, j, n, m);

        sol[i][j] = 0;

        if(rightSuccess or downSuccess)
            return true;

        return false;
}

int main()
{
    int n,m;
    cin>>n>>m;

    char path[100][100];

    for(int i=0;i<n;i++)
    {
            for(int j=0;j<m;j++)
            {
                    cin>>path[i][j];
            }
    }

    int sol[100][100] = {0};

    bool ans = ratInAMaze(path,sol, 0, 0, n-1, m-1);

    if(!ans)
    {
            cout<<-1<<endl;
    }

    cout<<"There are "<<count<<" paths to reach the destination"<<endl;

    return 0;
}
