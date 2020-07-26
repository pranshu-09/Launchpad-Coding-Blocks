#include <iostream>

using namespace std;

int fastPower(int a, int b)
{
        if(b==0)
            return 1;

        int ans = fastPower(a,b/2);
        ans *= ans;

        if(b&1)
        {
                return a*ans;
        }
        else
        {
                return ans;
        }
}

int main()
{
    int a,b;
    cin>>a>>b;

    int ans = fastPower(a,b);
    cout<<ans;

    return 0;
}
