#include <iostream>

using namespace std;

void floodFill(int a[][8], int i, int j, int toFill, int oldFill)
{
        int r = 8;
        int c = 8;

        if(i<0 or i>=r or j<0 or j>=c)
            return;

        if(a[i][j] != oldFill)
            return;

        a[i][j] = toFill;

        floodFill(a, i-1, j, toFill, oldFill);
        floodFill(a, i, j-1, toFill, oldFill);
        floodFill(a, i+1, j, toFill, oldFill);
        floodFill(a, i, j+1, toFill, oldFill);
}

void printMatrix(int a[][8])
{
        for(int i=0;i<8;i++)
        {
                for(int j=0;j<8;j++)
                {
                        cout<<a[i][j]<<" ";
                }
                cout<<endl;
        }
}

int main()
{
    int a[][8] = { {1, 1, 1, 1, 1, 1, 1, 1},
                           {1, 1, 1, 1, 1, 1, 0, 0},
                           {1, 0, 0, 1, 1, 0, 1, 1},
                           {1, 2, 2, 2, 2, 0, 1, 0},
                           {1, 1, 1, 2, 2, 0, 1, 0},
                           {1, 1, 1, 2, 2, 2, 2, 0},
                           {1, 1, 1, 1, 1, 2, 1, 1},
                           {1, 1, 1, 1, 1, 2, 2, 1}
                        };

        floodFill(a, 1, 1, 3, 1);

        printMatrix(a);

    return 0;
}
