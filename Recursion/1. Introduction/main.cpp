#include <iostream>

using namespace std;

int sumTillN(int n)
{
        if(n==0)
            return 0;

        int sum = n + sumTillN(n-1);
        return sum;
}

int factorial(int n)
{
       //Base Case
       if(n==0)
       {
                return 1;
       }

        //Recurisve Case
        int ans = n * factorial(n-1);
        return ans;
}

int fibonacci(int n)
{
        //Base Case
        if(n==0 or n==1)
                return n;

        //Recursive Case
        int f1 = fibonacci(n-1);
        int f2 = fibonacci(n-2);

        return (f1 + f2);
}

bool arrSorted(int a[], int n)
{
        //Base Case
        if(n==1)
            return true;

        //Recursive Case
        if(a[0]<a[1] and arrSorted(a+1,n-1))
            return true;

        return false;
}

int exponent(int a, int b)
{
        if(b==1)
            return a;

        int ans = a * exponent(a,b-1);
        return ans;
}

int main()
{
    int n;
    cin>>n;

        //SUM TILL N
        cout<<sumTillN(n);

        //FACTORIAL OF NUMBER
//    int ans = factorial(n);

//        FIBONACCI SERIES
//    int ans = fibonacci(n);

        // TELL IF ARRAY IS SORTED
//    int arr[] = {2,6,7,99,124,66};
//    n = 6;

//    bool ans = arrSorted(arr, n);
//
//    if(ans)
//        cout<<"Array is Sorted";
//    else
//        cout<<"Array is not Sorted";

        //EXPONENT OF NUMBER
//    int a, b;
//    cin>>a>>b;
//
//    int ans = exponent(a,b);
//    cout<<ans;




    return 0;
}
