//Given a number. Determine the minimum no. of steps required to reduce the number into one. 3 operations can be performed on the number ( n/3, n/2, (n-1) )

#include <iostream>

using namespace std;

int reduceToOne(int n)
{
        if(n==1)
        {
                return 0;
        }

        int count1 = INT_MAX, count2 = INT_MAX, count3 = INT_MAX;

        if(n%3 == 0)
        {
                count3 = 1 + reduceToOne(n/3);
        }

        if(n%2==0)
        {
                count2 = 1 + reduceToOne(n/2);
        }

        count1 = 1 + reduceToOne(n-1);

        int min_step = min(count1, min(count2, count3));

        return min_step;
}

int main()
{
    int n;
    cin>>n;

    cout<<reduceToOne(n);

    return 0;
}
