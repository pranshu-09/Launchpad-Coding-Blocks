#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

int returnMultiplication(int x, int y)
{
	return x*y;
}

int main()
{
	//Sum of all the elements of the array/vector -  accumulate()
	
	int arr[] = {5, 4, 78, 63, -87};
	int n = sizeof(arr)/sizeof(int);

	int sum = 0;
	sum = accumulate(arr, arr+n, sum);  // 3rd parameter is the intial sum.

	cout<<"Sum of all elements of the array "<<sum<<endl;

	// Similarly for vector
    vector<int> v{1, 2, 87,66, 888, -87, 23};

	int sum2 = 0;
	sum2 = accumulate(v.begin(), v.end(), sum2);

	cout<<"Sum of all elements of the vector "<<sum2<<endl;


	// We can also pass a user-defined or pre-defined function as 4th parameter to make accumulate compute what we wish for
	int multiply = 1;
	multiply = accumulate(arr, arr+n, multiply, returnMultiplication);

	cout<<"Product of all the elements of the array is "<<multiply<<endl; // Similarly for vector



	// partial_sum()

	int a[] = {1, 2, 3, 4, 5};
	int b[5];

	partial_sum(a, a+5, b);

	cout<<"Partial Sum : "<<endl;
	for(int i=0;i<5;i++)
		cout<<b[i]<<" ";

	int c[5];

	partial_sum(a, a+5, c, returnMultiplication);

	cout<<"Factorial : "<<endl;
	for(int i=0;i<5;i++)
		cout<<c[i]<<" ";

	return 0;

}