#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;

	int arr[1000];

	for(int i=0;i<n;i++)
		cin>>arr[i];

	int k;
	cin>>k;

	int i = 0, j = n-1;

	while(i < j)
	{
		if(arr[i] + arr[j] == k)
		{
			cout<<"Pair : "<<arr[i]<<" "<<arr[j]<<endl;
			i++;

		}

		else if(arr[i] + arr[j] < k)
		{
			i++;
		}

		else
		{
			j--;
		}
	}

	return 0;
}