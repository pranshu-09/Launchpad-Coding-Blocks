#include <iostream>

using namespace std;

string replacePi(string s)
{
        if(s.size()==0)
            return "";

        char ch = s[0];
        string ros = s.substr(1);

        string recursionResult = replacePi(ros);

        if(ch == 'p' and recursionResult[0]=='i')
        {
                return ("3.14" + recursionResult.substr(1));
        }
        else
        {
                return ch + recursionResult;
        }
}

int main()
{
    string input;
    cin>>input;

    cout<<replacePi(input);
    return 0;
}
