#include <iostream>

using namespace std;

int minimum(int arr[], int start, int end)
{
        if(start==end)
            return start;

        int k = minimum(arr, start+1, end);

        return (arr[start] < arr[k]) ? start : k;
}

void selectionSort(int arr[], int start, int end)
{
        if(start==end)
            return;

        int minIdx = minimum(arr, start, end);

        swap(arr[start], arr[minIdx]);

        selectionSort(arr, start+1, end);
}


int main()
{
    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    selectionSort(arr, 0, n-1);

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";


    return 0;
}
