#include<iostream>

using namespace std;

bool subsetSum(int arr[], int si, int sum, int n, int counter)
{
	if(si == n)
		{
			if(sum==0 and counter>0)
				return true;
			else
				return false;
		}

	bool exclude = subsetSum(arr, si+1, sum, n, counter);
	bool include = subsetSum(arr, si+1, sum + arr[si], n, counter+1);

	return exclude||include;

}

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		int n;
		cin>>n;

		int arr[n];

		for(int i=0;i<n;i++)
			cin>>arr[i];

		bool res = subsetSum(arr,0,0,n,0);

		if(res)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}

	return 0;
}
