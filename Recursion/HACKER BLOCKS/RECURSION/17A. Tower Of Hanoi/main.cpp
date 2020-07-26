#include<iostream>
using namespace std;

void towerOfHanoi(int n, char src, char dest, char help)
{
	if(n==0)
		return;

	towerOfHanoi(n-1, src, help, dest);
	cout<<"Move ring "<<n<<" from "<<src<<" to "<<dest<<endl;
	towerOfHanoi(n-1, help, dest, src);
}

int main()
{
	int n;
	cin>>n;

	towerOfHanoi(n, 'A', 'C', 'B');
	return 0;
}
