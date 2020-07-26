#include<iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

vector<string> res;

void printDictionaryLarger(string s, string check, string ans)
{

	if(s.size()==0)
	{
		if(ans < check)
			res.push_back(ans);

		return;
	}

	for(int i=0;i<s.size();i++)
	{
		char ch = s[i];
		string ros = s.substr(0,i) + s.substr(i+1);

		printDictionaryLarger(ros,check, ans+ch);
	}
}

int main()
{
	string s;
	cin>>s;

	printDictionaryLarger(s,s,"");

	sort(res.begin(),res.end());

	for(int i=0;i<res.size();i++)
		cout<<res[i]<<endl;

	return 0;
}
