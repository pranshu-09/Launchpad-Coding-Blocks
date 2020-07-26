#include <iostream>

using namespace std;

void quickSort(long A[],long low, long high)
{
    if(low>high)
    {
        return;
    }

    //Recursive Case
    long left = low;
    long right = high;

    long mid = left + (right-left)/2;

    long pivot = A[mid];

    while(left<=right)
    {
        while(A[left]<pivot)
        {
            left++;
        }

        while(A[right]>pivot)
        {
            right--;
        }

        if(left<=right)
        {
            swap(A[left],A[right]);
            left++;
            right--;
        }
    }

    quickSort(A,low,right);
    quickSort(A,left,high);

}

int main()
{
    long N;
    cin>>N;

    long A[N];

    for(long i=0;i<N;i++)
    {
        cin>>A[i];
    }

    long low = 0;
    long high = N-1;

    quickSort(A,low,high);

    for(long i=0;i<N;i++)
    {
        cout<<A[i]<<" ";
    }


    return 0;
}
