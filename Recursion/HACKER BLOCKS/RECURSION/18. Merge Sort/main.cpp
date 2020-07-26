#include <iostream>

using namespace std;

void merge(long a[], long start, long end)
{
    long n = end-start+1;

    long mid = start+(end-start)/2;

    long temp[n],k=0;

    long start1=start;
    long start2=mid+1;

    while(start1<=mid && start2<=end)
    {
        if(a[start1]<=a[start2])
        {
            temp[k++]=a[start1];
            start1++;
        }
        else
        {
            temp[k++]=a[start2];
            start2++;
        }
    }

         if(start1<=mid)
        {
            for(long i=start1;i<=mid;i++)
            {
                temp[k++]=a[i];
            }
        }

        if(start2<=end)
        {
            for(long i=start2;i<=end;i++)
            {
                temp[k++]=a[i];

            }
        }

        long pos = 0;

        for(long i=start;i<=end;i++)
            {
                a[i]=temp[pos++];
            }
    }


void mergeSort(long a[],long start, long end)
{
    if(start==end)
        return;

    long mid = start + (end-start)/2;

    mergeSort(a,start,mid);
    mergeSort(a,mid+1,end);

    merge(a,start,end);
}

int main()
{
    long N;
    cin>>N;

    long a[N];

    for(long i=0;i<N;i++)
    {
        cin>>a[i];
    }

    long start = 0;
    long end = N-1;

    mergeSort(a,start,end);

    for(long i=0;i<N;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
