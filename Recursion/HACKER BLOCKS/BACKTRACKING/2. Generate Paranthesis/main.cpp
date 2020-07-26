#include<iostream>
using namespace std;

void generateParanthesis(int n, int openBracket, int closeBracket, string ans)
{
	if(closeBracket==n)
	{
		cout<<ans<<endl;
		return;
	}

	if(openBracket>closeBracket)
		generateParanthesis(n, openBracket, closeBracket+1, ans + ")");

	if(openBracket<n)
		generateParanthesis(n, openBracket+1, closeBracket, ans + "(");
}

int main()
{
	int n;
	cin>>n;

	generateParanthesis(n,0,0,"");
	return 0;
}
