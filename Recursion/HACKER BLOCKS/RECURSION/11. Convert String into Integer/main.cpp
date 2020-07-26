#include<iostream>
#include <math.h>

using namespace std;

void convertStringToInt(string s, long long int ans)
{
	if(s.size()==0)
	{
		cout<<ans;
		return;
	}

	char ch = s[0];
	int ch_int = ch - '0';

	string ros = s.substr(1);
	int dig = s.size()-1;
	long long int multiply_10 = pow(10, dig);

	convertStringToInt(ros, ans + ch_int*multiply_10);

}

int main()
{
	string s;
	cin>>s;

	convertStringToInt(s,0);

	return 0;
}
