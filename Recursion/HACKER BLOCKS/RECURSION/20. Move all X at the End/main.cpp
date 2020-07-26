#include<iostream>
using namespace std;

string moveXToEnd(string s)
{
	if(s.size()==0)
	{
		return "";
	}

	char ch = s[0];
	string ros = s.substr(1);

	string recursionResult = moveXToEnd(ros);

	if(ch=='x')
	{
		return recursionResult + ch;
	}
	else
	{
		return ch + recursionResult;
	}
}

int main()
{
	string s;
	cin>>s;

	cout<<moveXToEnd(s);

	return 0;
}
