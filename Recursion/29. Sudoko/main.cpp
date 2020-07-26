#include <iostream>
#include <math.h>

using namespace std;

bool canPlace(int mat[][9], int i, int j, int n, int num)
{
        //Checking for row and column
        for(int x=0; x<n;x++)
        {
                if(mat[x][j] == num or mat[i][x] == num)
                    return false;
        }

        int rn = sqrt(n);
        int sx = (i/rn)*rn;
        int sy = (j/rn)*rn;

        for(int i=sx;i<sx+rn; i++)
        {
            for(int j=sy; j<sy+rn; j++)
            {
                    if(mat[i][j] == num)
                        return false;
            }
        }

        return true;
}

bool solveSudoku(int mat[][9], int i, int j, int n)
{
        //Base Case
        if(i==n)
        {
                for(int i=0;i<n;i++)
                {
                        for(int j=0;j<n;j++)
                        {
                                cout<<mat[i][j]<<" ";
                        }
                        cout<<endl;
                }
                return true;
        }

        //Case at end of each row
        if(j == n)
        {
                return solveSudoku(mat, i+1, 0, n);
        }

        //When no. already present
        if(mat[i][j] != 0)
        {
                return solveSudoku(mat, i, j+1, n);
        }

        //Recursive Case
        for(int num=1;num<=n; num++)
        {
                if(canPlace(mat, i, j, n, num))
                {
                        mat[i][j] = num;

                        bool restSudoku = solveSudoku(mat, i, j+1, n);

                        if(restSudoku)
                            return true;
                }
        }

        mat[i][j] = 0;
        return false;

}

int main()
{
    int mat[9][9] = {
                                {5,3,0,0,7,0,0,0,0},
                                {6,0,0,1,9,5,0,0,0},
                                {0,9,8,0,0,0,0,6,0},
                                {8,0,0,0,6,0,0,0,3},
                                {4,0,0,8,0,3,0,0,1},
                                {7,0,0,0,2,0,0,0,6},
                                {0,6,0,0,0,0,2,8,0},
                                {0,0,0,4,1,9,0,0,5},
                                {0,0,0,0,8,0,0,7,9},
    };

    solveSudoku(mat, 0, 0, 9);

    return 0;
}
