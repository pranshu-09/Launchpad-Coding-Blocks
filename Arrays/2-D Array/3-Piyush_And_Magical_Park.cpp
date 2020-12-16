#include<iostream>
using namespace std;

void piyushAndPark(char arr[][101], int n, int m, int k, int s)
{
	int flag = 0;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(arr[i][j] == '.')
				s -= 2;
			else if(arr[i][j] == '*')
				s += 5;
			else if(arr[i][j] == '#')
            {
                break;
            }

			if(j != m-1)
				s--;

			if(s < k)
			{
				flag=1;
				break;
			}
		}
	}

	if(flag)
		cout<<"No";
	else
		cout<<"Yes"<<endl<<s;
}

int main()
{
	int n, m, k, s;
	cin>>n>>m>>k>>s;

	char arr[101][101];

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>arr[i][j];

	piyushAndPark(arr, n, m, k, s);
	
	return 0;
}