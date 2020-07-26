//Given a number. Determine the minimum no. of perfect squares required to make the number

#include <iostream>

using namespace std;

int perfectSquares(int n)
{
        if(n==0)
            return 0;

        int minValue = INT_MAX;

        for(int i=1; i*i<=n; i++)
        {
                int currentAnswer = 1 + perfectSquares(n - i*i);

                minValue = min(minValue, currentAnswer);
        }

        return minValue;
}

int main()
{
    int n;
    cin>>n;

    cout<<perfectSquares(n);


    return 0;
}
