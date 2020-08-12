#include<iostream>
#include <algorithm>

using namespace std;

// Defining a comparator function
bool compare(int a, int b)
{
	cout<<"Comparing "<<a<<" and "<<b<<endl;
	return a > b;
}

int main()
{
	int n;
	cin>>n;

	int arr[1000];

	for(int i=0;i<n;i++)
		cin>>arr[i];

	// Sort STL
	// sort(arr, arr+n);

	// To sort in descending order, we can create our comparator function
	sort(arr, arr+n, compare); // We pass the function name as the parameter to the sort function

	// Or we can use
	// sort(arr, arr+n, greater<int> ());

	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";

	cout<<endl; 


	return 0;
}

