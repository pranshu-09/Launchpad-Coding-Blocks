#include<iostream>
#include <set>
using namespace std;

set<string> str;

void printPossiblePermuatations(string s, string ans)
{
	if(s.size()==0)
	{
		str.insert(ans);
		return;
	}

	for(int i=0;i<s.size();i++)
	{
		swap(s[0], s[i]);

		char ch = s[0];

		string ros = s.substr(1);

		printPossiblePermuatations(ros, ans+ch);

		swap(s[0], s[i]);
	}
}

int main()
{
	string s;
	cin>>s;

	printPossiblePermuatations(s,"");

	for(auto it:str)
	{
		cout<<it<<endl;
	}

	return 0;
}
