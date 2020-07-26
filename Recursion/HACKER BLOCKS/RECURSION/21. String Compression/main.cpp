#include<iostream>
using namespace std;

void stringbrute(string s)
{
	int count=1;

	for(int i=0;i<s.size()-1;i++)
	{
		if(s[i] == s[i+1])
		{
			count++;
		}
		else
		{
			cout<<s[i]<<count;
			count=1;
		}
	}
	cout<<s[s.size()-1]<<count;

}

int main()
{
	string s;
	cin>>s;

	stringbrute(s);


	return 0;
}
