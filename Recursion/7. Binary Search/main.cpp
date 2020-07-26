#include <iostream>

using namespace std;

int binarySearch(int arr[], int start, int end, int key)
{
        if(start>end)
            return -1;

        int mid= (start+end)/2;

        if(arr[mid] == key)
        {
               return mid;
        }
        else if(arr[mid]<key)
        {
            return binarySearch(arr, mid+1,end,key);
        }
        else
        {
            return binarySearch(arr,start,mid-1,key);
        }

}

int main()
{
    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    int key;
    cin>>key;

    int idx = binarySearch(arr,0,n-1,key);
    cout<<idx;

    return 0;
}
