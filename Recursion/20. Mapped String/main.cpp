#include <iostream>

using namespace std;

void mappedString(string s, string out)
{
        if(s.size()==0)
        {
                cout<<out<<endl;
                return;
        }

        char ch1 = s[0];
        int ch1_int = ch1 - '0';

        char alpha1 = ch1_int + 'A' - 1;

        string ros1 = s.substr(1);

        mappedString(ros1, out + alpha1);

        if(s.length()>1)
        {
                char ch2 = s[1];
                int ch2_int = ch2 - '0';

                int number = ch1_int*10 + ch2_int;

                if(number <= 26)
                {
                    char alpha2 = number + 'A' - 1;

                    string ros2 = s.substr(2);

                    mappedString(ros2, out + alpha2);
                }
        }
}

int main()
{
    string inp;
    cin>>inp;

    mappedString(inp, "");
    return 0;
}
