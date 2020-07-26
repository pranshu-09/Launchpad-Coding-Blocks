#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<bits/stdc++.h>

using namespace std;

set<vector<int> > s;

void sumItUp(int arr[], int si, int n, int sum , int targetSum, vector<int> elem)
{
	if(si==n)
	{
		if(sum==targetSum)
			{
				sort(elem.begin(), elem.end());
				s.insert(elem);
			}
		return;
	}

	sumItUp(arr, si+1, n, sum, targetSum, elem);
	elem.push_back(arr[si]);
	sumItUp(arr, si+1, n, sum + arr[si], targetSum, elem);
}

void print(vector<int> p)
{
	for(int i=0;i<p.size();i++)
		cout<<p[i]<<" ";
}

int main()
{
	int n;
	cin>>n;

	int arr[n];

	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	int targetSum;
	cin>>targetSum;

	vector<int> elem;

	sumItUp(arr, 0, n, 0, targetSum, elem);

	for(auto it=s.begin(); it!=s.end(); it++)
	{
		print(*it);
		cout<<endl;
	}

	return 0;
}
