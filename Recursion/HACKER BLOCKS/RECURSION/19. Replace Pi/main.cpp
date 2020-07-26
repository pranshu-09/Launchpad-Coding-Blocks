#include<iostream>
using namespace std;

void replacePi(string s, string ans)
{
	if(s.size()==0)
	{
		cout<<ans<<endl;
		return;
	}

	char ch = s[0];
	string ros = s.substr(1);

	if(ch=='p' and ros[0]=='i')
	{
		replacePi(ros.substr(1), ans + "3.14");
	}
	else
	{
		replacePi(ros, ans+ch);
	}
}

int main()
{
	int n;
	cin>>n;

	while(n--)
	{
		string s;
		cin>>s;

		replacePi(s,"");
	}
}
