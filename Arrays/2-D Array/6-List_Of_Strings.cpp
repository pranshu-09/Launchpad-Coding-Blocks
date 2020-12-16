#include<iostream>
using namespace std;

int main()
{
	char arr[100][1000];

	int n;
	cin>>n;

	// To input a charcter array that may have spaces in it
	cin.get();
	for(int i=0;i<n;i++)
		cin.getline(arr[i], 1000);


	for(int i=0;i<n;i++)
		cout<<arr[i]<<endl;


	// To input a string which may have spaces in it
	string p;

	getline(cin, p);

	cout<<p<<endl;

	return 0;
}