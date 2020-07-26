#include <iostream>

using namespace std;

void mappedStrings(string s, string ans)
{
	if(s.size()==0)
	{
		cout<<ans<<endl;
		return;
	}

	char ch = s[0];
	int ch_int = ch - '0';

	char alpha = ch_int + 'A' - 1;

	string ros = s.substr(1);

	mappedStrings(ros, ans+alpha);

	if(s.size()>1)
	{
		char ch2 = s[1];
		int ch2_int = ch2 - '0';

		int number = ch_int*10 + ch2_int;

		if(number<=26)
		{
			char alpha2 = number + 'A' - 1;

			string ros2 = s.substr(2);

			mappedStrings(ros2, ans + alpha2);
		}
	}
}

int main()
{
	string s;
	cin>>s;

	mappedStrings(s,"");
}
