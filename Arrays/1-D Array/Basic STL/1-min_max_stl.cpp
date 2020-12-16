#include<bits/stdc++.h>
using namespace std;

int main()
{
	// STL for finding minimum and maximum element in the array
	int arr[] = {5, 4, 78, 63, -87};
	int n = sizeof(arr)/sizeof(int);

	int maxElem = *max_element(arr, arr+n);
	int minElem = *min_element(arr, arr+n);

	cout<<maxElem<<" "<<minElem<<endl;


	//Finding min and max element in string
	string s[] = {"abc", "acb", "bac", "cba"};

    cout<<*max_element(s, s+4)<<endl;
    cout<<*min_element(s, s+4)<<endl;


    //Finding min and max element in vector
    vector<int> v{1, 2, 87,66, 888, -87, 23};

    int maxElem1 = *max_element(v.begin(), v.end());
	int minElem1 = *min_element(v.begin(), v.end());

	cout<<maxElem1<<" "<<minElem1<<endl;

	return 0; 
}