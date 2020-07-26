//Given total number of people. People have to go in party. They can go either in pair or individually. Determine total number of ways possible.

#include <iostream>

using namespace std;

int pairingProblem(int n)
{
        if(n==1 or n==2)
        {
                return n;
        }

         // If a person decide to go in pair, then we have to choose 2 people from n and call for rest (n-2). The person has to decide a partner from the rest (n-1) people to go
         // with him/her. So, we have to multiply it with (n-1).
        int pair = pairingProblem(n-2);

        //If a person decide to go individually, then we will call for rest (n-1) people
        int individual = pairingProblem(n-1);

        int total = individual + (n-1)*pair;

        return total;
}

int main()
{
    int n;
    cin>>n;

    cout<<pairingProblem(n);

    return 0;
}
