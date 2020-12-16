#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void returnReverse(int arr[], int start, int end)
{
	while(start<end)
	{
		swap(arr[start], arr[end]);
		start++;
		end--;
	}
}

void rotateArray(int arr[], int n, int d)
{
	if(d==0)
		return;

	//Reverse elements from index 0 -> d-1
	returnReverse(arr, 0, d-1);

	//Reverse elements from index d -> n-1
	returnReverse(arr, d, n-1);

	//Reverse the complete array
	returnReverse(arr, 0, n-1);
}


// Using reverse STL

void rotateArrayUsingSTL(vector<int> &arr2, int n ,int d)   // We did & because we need to reflect the changes in the array in the main function as well
{
	if(d==0)
		return;

	reverse(arr2.begin(), arr2.begin()+d);
	reverse(arr2.begin()+d, arr2.end());
	reverse(arr2.begin(), arr2.end());

}

int main()
{
	int n, d;
	cin>>n>>d;

	d = d % n;  // Don't forget to take d % n as it will take care of situation when d>n

	// int arr[100];

	// for(int i=0;i<n;i++)
	// 	cin>>arr[i];

	// rotateArray(arr, n, d);

	// for(int i=0;i<n;i++)
	// 	cout<<arr[i]<<" ";


	// Using reverse STL and vector<int>

	vector<int> arr2;

	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;

		arr2.push_back(x);
	}

	rotateArrayUsingSTL(arr2, n, d);

	for(int x: arr2)
		cout<<x<<" ";

	return 0;
}