//Given a number which signifies digits of the binary number. Determine the count of binary combinations that can be made which do not have consecutive 1.

#include <iostream>

using namespace std;

int countBinaryStrings(int n)
{

        if(n==1 or n==2)
        {
                return n+1;
        }

        int one = countBinaryStrings(n-2);  //If we place 1 at the current position, then we can only place 0 at the next position as we do not need consecutive ones. Hence, we will call for the rest (n-2) positions
        int zero = countBinaryStrings(n-1); //If we place 0 at the current position, then we can either place 0 or 1 at next position. Hence, we will call for the rest (n-1) positions

        return (one + zero);
}


int main()
{
    int n;
    cin>>n;

    cout<<countBinaryStrings(n);

    return 0;
}
