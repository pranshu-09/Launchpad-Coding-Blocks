#include <iostream>

using namespace std;

string searchIn [] = {"prateek", "sneha", "deepak", "arnav", "shikha", "palak", "utkarsh", "divyam", "vidhi", "sparsh", "akku"};
string keypad[] = { "","", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

void printStrings(string s, string ans)
{
        if(s.size()==0)
        {
                for(int i=0;i<11;i++)
                {
                        for(int j=0;j<(searchIn[i].size() - ans.size()); j++)
                        {
                                if(ans == searchIn[i].substr(j, ans.size()))
                                {
                                        cout<<searchIn[i]<<endl;
                                }
                        }
                }

            return;
        }

        int idx = s[0] - '0';
        string ros  = s.substr(1);

        string key = keypad[idx];

        for(int i=0;i<key.size();i++)
        {
                char ch = key[i];
                printStrings(ros, ans + ch);
        }
}

int main()
{
    string in;
    cin>>in;

    printStrings(in,"");
    return 0;
}
