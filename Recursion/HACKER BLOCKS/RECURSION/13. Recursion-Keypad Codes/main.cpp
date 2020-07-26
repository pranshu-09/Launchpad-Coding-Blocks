#include<iostream>
using namespace std;

string keypad[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wx", "yz"};
int count=0;

void printCodes(string s, string ans)
{
	if(s.size()==0)
	{
		cout<<ans<<" ";
		count++;
		return;
	}

	char ch = s[0];
	int ch_int = ch -'0';

	string key = keypad[ch_int - 1];

	string ros = s.substr(1);

	for(int i=0;i<key.size();i++)
	{
		char ch = key[i];
		printCodes(ros, ans+ch);
	}

}

int main()
{
	string s;
	cin>>s;

	printCodes(s,"");
	cout<<endl<<count;

	return 0;
}
