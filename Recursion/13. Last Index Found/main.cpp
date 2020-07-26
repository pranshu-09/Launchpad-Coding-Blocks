#include <iostream>

using namespace std;

int lastIndexFound(int arr[], int i, int n, int key)
{
        if(i == n)
            return -1;

        int index = lastIndexFound(arr, i+1, n, key);

        //On returning after the base case, recursion checks whether the last element is the key or not. If it is, then we will return the idx or else return -1
        if(index == -1)
        {
                if(arr[i] == key)
                    return i;
                else
                    return -1;
        }
        //If the index found is not -1, it means we have got the last index where key is found. Hence, we will return the index
        else
            return index;
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

    int idx = lastIndexFound(arr,0,n,key);

    cout<<"Last Index of "<<key<<" found at " << idx<<" index";

    return 0;
}
