#include <iostream>
using namespace std;

int count=0;

void towerOfHanoi(int n, string src, string dest, string help)
{
    if(n==0)
        return;

    towerOfHanoi(n-1, src, help, dest);
    cout<<"Move "<<n<<"th disc from "<<src<<" to "<<dest<<endl;
    count++;
    towerOfHanoi(n-1, help, dest, src);

}

int main()
{
    int n;
    cin>>n;

    towerOfHanoi(n, "T1", "T2", "T3");
    cout<<count;

}
