#include <iostream>

using namespace std;

int countMazePath(int sr, int sc, int er, int ec)
{
        if(sr==er and sc==ec)
        {
                return 1;
        }

        if(sr>er or sc>ec)
            return 0;

        //A path will be combination of moving horizontally right and vertically
        int rightMovement = countMazePath(sr, sc+1, er, ec);
        int downMovement = countMazePath(sr+1, sc, er, ec);

        return rightMovement + downMovement;
}

void printMazePath(int sr, int sc, int er, int ec, string ans)
{
        if(sr==er and sc==ec)
        {
                cout<<ans<<endl;
                return;
        }

        if(sr>er or sc>ec)
        {
                return;
        }

        printMazePath(sr, sc+1, er, ec, ans+'H');
        printMazePath(sr+1, sc, er, ec, ans+'V');
}

int main()
{
    int er, ec;
    cin>>er>>ec;

    printMazePath(0,0,er,ec,"");

    cout<<"Paths Possible are "<<countMazePath(0, 0, er, ec);
    return 0;
}
