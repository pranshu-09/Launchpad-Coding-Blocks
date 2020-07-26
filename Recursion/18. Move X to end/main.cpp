#include <iostream>

using namespace std;

string moveXToEnd(string s)
{
        if(s.size()==0)
            return "";

        char ch = s[0];
        string ros = s.substr(1);

        if(ch == 'x')
        {
                return (moveXToEnd(ros) + ch);
        }
        else
        {
                return (ch + moveXToEnd(ros));
        }
}

int main()
{
    string input;
    cin>>input;

    cout<<moveXToEnd(input);

    return 0;
}
