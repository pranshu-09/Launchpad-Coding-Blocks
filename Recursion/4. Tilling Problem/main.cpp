#include <iostream>

using namespace std;

int tillingProblem(int n, int m)
{
        //Base Case
        if(n<m)
            return 1;
        else if(n==m)
            return 2;

        //Recurrsive Case
        int curr_ways = tillingProblem(n-1,m) + tillingProblem(n-m,m);
        return curr_ways;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int ways = tillingProblem(n,m);

        cout<<ways<<endl;
    }

    return 0;
}
