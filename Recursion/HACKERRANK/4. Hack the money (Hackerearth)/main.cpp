#include<iostream>
using namespace std;

bool hackMoney(long long int i, long long int n)
{
	if(i==n)
		return true;

	if(i>n)
		return false;

	bool ten = hackMoney(i*10, n);
	bool twenty = hackMoney(i*20, n);

	return ten or twenty;
}

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		long long int n;
		cin>>n;

		if(hackMoney(1, n))
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		}
	}

	return 0;
}


