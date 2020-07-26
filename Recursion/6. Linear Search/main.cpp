#include <iostream>

using namespace std;

bool linearSearch(int arr[], int n, int key)
{
        if(n==0)
            return false;

        if(arr[0]==key or linearSearch(arr+1,n-1,key))
            return true;

        return false;
}

int returnKey(int arr[], int i, int n, int key)
{
        if(i==n)
            return -1;

        if(arr[i] == key)
            return i;

        return returnKey(arr,i+1,n,key);
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

    //CHECK IF KEY PRESENT OR NOT
    if(linearSearch(arr,n,key))
        cout<<key<<" is present in the array";
    else
        cout<<key<<" is not present in the array";

    cout<<endl;

    //PRINT THE INDEX OF THE KEY
    int idx = returnKey(arr,0,n,key);

    if(idx==-1)
        cout<<"Element not found";
    else
        cout<<"Element found at "<<idx<<" index";

    return 0;
}
