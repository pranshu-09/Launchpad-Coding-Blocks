#include <iostream>

using namespace std;

bool isPossible(int arr[], int si, int sum, int total, int n)
{
        if(2*sum == total)
            return true;

        if(si == n or 2*sum > total)
            return false;

        bool exclude = isPossible(arr, si+1, sum, total, n);
        bool include = isPossible(arr, si+1, sum+arr[si], total, n);

        return exclude or include;
}

bool canPartition(int arr[], int n)
{
        int total=0;

        for(int i=0;i<n;i++)
            total += arr[i];

        if(total&1)
            return false;

        else
            return isPossible(arr, 0, 0, total, n);
}

int main()
{
    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    bool res = canPartition(arr,n);

    if(res)
        cout<<"Array can be partitioned into 2 subsets with equal sum"<<endl;
    else
        cout<<"Array cannot be partitioned into 2 subsets with equal sum"<<endl;

    return 0;
}
