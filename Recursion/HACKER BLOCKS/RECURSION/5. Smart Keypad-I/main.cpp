#include <iostream>

using namespace std;

string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

void printCodes(string s, string ans)
{
        if(s.size()==0)
        {
            cout<<ans<<endl;
            return;
        }

        int ch = s[0] - '0';

        string key = table[ch];
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
    return 0;
}
