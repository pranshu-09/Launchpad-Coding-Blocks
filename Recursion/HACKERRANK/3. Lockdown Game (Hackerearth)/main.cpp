#include<iostream>
#include<set>
using namespace std;

set<int> eliminated;        //To store all the players which got eliminated

void locksdownGame(int i, int n, int idx, string s)
{
	i = i % n;
	if(i==0)        // To make a cycle
		i=n;

	idx = idx%(s.size());       //To make index of string cyclable

	if(!eliminated.count(i))        //To check whether for current element and index, the element is inserted in the set or not
	{
		if(s[idx]=='y')
		{
			eliminated.insert(i);

			if(eliminated.size()==n-1)      //If the size of set becomes n-1, it means only 1 element is left and rest all are eliminated. Hence, we got out winner. So return
			{
				return;
			}

			locksdownGame(i+1, n, idx+1, s);
		}
		else
		{
			locksdownGame(i+1, n, idx+1, s);
		}
	}
	else
	{
		locksdownGame(i+1, n, idx, s);      //If the element is inserted in the set, it means the element is eliminated before and we would move to next element without changing idx
	}

}

int main()
{
	int n;
	cin>>n;

	string s;
	cin>>s;

	locksdownGame(1, n, 0, s);

	int ans=0;

	for(auto it:eliminated)
	{
		ans += it;
	}

	int sum_till_n = ((n)*(n+1))/2;     // We are finding the sum of all nos. uptil n and the sum of elements present in the set. By subtracting, we would get the element which has won

	cout<<(sum_till_n - ans);
}
