#include <iostream>

using namespace std;

bool isSafe(int board[][10], int i, int j, int n)
{
        //Checking if column above has been placed by any queen
        for(int row=0;row<i;row++)
        {
                if(board[row][j] == 1)
                    return false;
        }

        //Checking for left diagonal
        int x = i;
        int y = j;

        while(x>=0 and y>=0)
        {
                if(board[x][y] == 1)
                    return false;

                x--;
                y--;
        }

        //Checking for right diagonal
        x = i;
        y = j;

        while(x>=0 and y<n)
        {
                if(board[x][y] == 1)
                {
                        return false;
                }

                x--;
                y++;
        }

        //If no above condition is satisfied, then we can place the queen at board[i][j]. Therefore return true to solveNQueen
        return true;
}

bool solveNQueen(int board[][10], int i, int n)
{
        //Base Case
        if(i == n)
        {
                //Print the matrix
                for(int i=0;i<n;i++)
                {
                        for(int j=0;j<n;j++)
                        {
                                if(board[i][j] == 1)
                                {
                                        cout<<"Q ";
                                }
                                else
                                {
                                        cout<<"_ ";
                                }
                        }

                        cout<<endl;
                }

                cout<<endl<<endl;

                return false;  //For printing every configuration of the N-Queens, just return false. For printing the first configuration of the N-Queens, return true
        }

        //Recursive Case
        for(int j=0;j<n; j++)
        {
                if(isSafe(board, i , j, n))
                {
                        board[i][j] = 1;

                        bool restMatrix = solveNQueen(board,i+1,n);

                        if(restMatrix)
                        {
                                return true;
                        }

                        //If restMatrix becomes false, we would do backtracking and make board[i][j] = 0 again

                        board[i][j] = 0;
                }
        }

        return false;

}

int main()
{
    int n;
    cin>>n;

    int board[10][10] = {0};

    solveNQueen(board, 0, n);

    return 0;
}
