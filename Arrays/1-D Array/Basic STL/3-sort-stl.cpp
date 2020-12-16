#include<iostream>
#include<algorithm>

using namespace std;

struct Interval 
{ 
    int start, end; 
}; 
  
// Compares two intervals according to staring times. 
bool compareInterval(Interval i1, Interval i2) 
{ 
    return (i1.start < i2.start); 
} 


int main()
{
	int a[] = {8, 61, 1, 32, -11};

	sort(a, a+5);

	for(int i=0;i<5;i++)
		cout<<a[i]<<" ";

	cout<<endl;


	//To Sort in Decreasing Order

	sort(a, a+5, greater<int>());

	for(int i=0;i<5;i++)
		cout<<a[i]<<" ";


	// Passing a comparator function to sort()

    Interval arr[] =  { {6,8}, {1,9}, {2,4}, {4,7} }; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    // sort the intervals in increasing order of 
    // start time 
    sort(arr, arr+n, compareInterval); 
  
    cout << "Intervals sorted by start time : \n"; 
    for (int i=0; i<n; i++) 
       cout << "[" << arr[i].start << "," << arr[i].end 
            << "] "; 
  


	return 0;
}