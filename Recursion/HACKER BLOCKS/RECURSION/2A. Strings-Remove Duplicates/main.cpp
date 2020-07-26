#include <iostream>

using namespace std;

void removeDuplicates(string s, string ans)
{
        if(s.size()==0)
        {
                cout<<ans;
                return;
        }

        char ch = s[0];
        string ros = s.substr(1);

        if(ch == ros[0])
        {
                removeDuplicates(ros, ans);
        }
        else
        {
                removeDuplicates(ros, ans+ch);
        }
}

int main()
{
    string s;
    cin>>s;

    removeDuplicates(s,"");

    return 0;
}
