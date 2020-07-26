#include <iostream>

using namespace std;

long long int dp[1000][1000];

long long int optimalGameStrategy(long long int arr[], long long int start, long long int end)
{
        if(start>end)
            return 0;

        if(dp[start][end]!=-1)
                return dp[start][end];

        long long int A1 = arr[start] + min(optimalGameStrategy(arr, start+1, end-1), optimalGameStrategy(arr, start+2,end));
        long long int A2 = arr[end] + min(optimalGameStrategy(arr, start+1, end-1), optimalGameStrategy(arr, start,end-2));

        long long int ans = max(A1, A2);
        dp[start][end] = ans;

        return dp[start][end];
}

int main()
{
    long long int n;
    cin>>n;

    long long int arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    for(int i=0;i<n;i++)
    {
            for(int j=0;j<n;j++)
            {
                    dp[i][j] = -1;
            }
    }

    cout<<optimalGameStrategy(arr, 0, n-1);

    return 0;
}
