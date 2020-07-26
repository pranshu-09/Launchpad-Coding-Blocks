#include<iostream>

using namespace std;

int classAssignment(int n)
{
	if(n==1 or n==2)
		return n+1;

	int a = classAssignment(n-1);
	int b = classAssignment(n-2);

	return a+b;
}

int main()
{
	int n;
	cin>>n;

	int no;

	for(int i=1;i<=n;i++)
	{
		cin>>no;

		cout<<"#"<<i<<" : "<<classAssignment(no)<<endl;
	}
	return 0;
}
