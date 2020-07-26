#include <iostream>

using namespace std;

int count=0;

void printSubsequences(string s, string ans)
{
        if(s.size()==0)
        {
                cout<<ans<<" ";
                count++;
                return;
        }

        char ch = s[0];
        string ros = s.substr(1);

        printSubsequences(ros, ans);
        printSubsequences(ros,ans+ch);
}

int main()
{
    string s;
    cin>>s;

    printSubsequences(s, "");
    cout<<endl<<count;

    return 0;
}
