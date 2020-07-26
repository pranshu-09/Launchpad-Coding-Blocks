#include <iostream>

using namespace std;

char keypad[][10] = { "", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void keypadPrint(char in[], char out[], int i, int j)
{
        if(in[i]=='\0')
        {
                out[j] = '\0';
                cout<<out<<endl;
                return;
        }

        int digit = in[i] - '0';

        if(digit==0 or digit==1)
        {
                keypadPrint(in, out, i+1,j);
        }

        for(int k=0; keypad[digit][k]!='\0'; k++)
        {
                out[j] = keypad[digit][k];
                keypadPrint(in, out, i+1, j+1);
        }

}

string keypad_no[10] = { "", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void printKeypad(string s, string ans)
{
        if(s.size()==0)
        {
            cout<<ans<<endl;
            return;
        }

        int idx = s[0] - '0';
        string key = keypad_no[idx];

        string ros = s.substr(1);

        for(int i=0; i<key.size(); i++)
        {
                char ch = key[i];
                printKeypad(ros, ans+ch);
        }
}

int main()
{
//    char in[20], out[20];
//    cin>>in;

//    keypadPrint(in, out, 0, 0);

    string s;
    cin>>s;
    printKeypad(s,"");

    return 0;
}
