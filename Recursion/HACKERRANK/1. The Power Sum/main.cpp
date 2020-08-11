#include <iostream>
#include <math.h>

using namespace std;

int powerSum(int X, int N, int i)
{
    int value = (X - pow(i, N));

    if(value < 0)
        return 0;

    if(value == 0)
        return 1;

    int valPossible = powerSum(value , N, i + 1);
    int valNotPossible = powerSum(X, N, i+1);

    return valPossible + valNotPossible;
}

int main()
{
    int X,N;
    cin>>X>>N;

    cout<<powerSum(X,N,1);
    return 0;
}
