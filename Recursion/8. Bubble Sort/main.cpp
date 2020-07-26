#include <iostream>

using namespace std;

void bubbleSort(int arr[], int n)
{
        if(n==1)
            return;

        for(int j=0;j<=n-2;j++)
        {
                if(arr[j]>arr[j+1])
                    swap(arr[j],arr[j+1]);
        }

        bubbleSort(arr, n-1);
}

void bubbleSort2(int arr[], int j, int n)
{
        if(n==1 or j==n-1)
            return;

        if(arr[j] > arr[j+1])
            swap(arr[j],arr[j+1]);

        bubbleSort2(arr,j+1,n);

        bubbleSort2(arr,0,n-1);
}

void bubbleSort3(int arr[], int j, int n)
{
        if(n==1)
            return;

        if(j==n-1)
        {
            bubbleSort3(arr,0,n-1);
            return;
        }

        if(arr[j] > arr[j+1])
            swap(arr[j],arr[j+1]);

        bubbleSort3(arr,j+1,n);
}


int main()
{
    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    bubbleSort(arr,n);

    for(int i=0;i<n;i++)
    {
            cout<<arr[i]<<" ";
    }
    cout<<endl;

    bubbleSort2(arr,0,n);
    for(int i=0;i<n;i++)
    {
            cout<<arr[i]<<" ";
    }
    cout<<endl;

    bubbleSort3(arr,0,n);
    for(int i=0;i<n;i++)
    {
            cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}
