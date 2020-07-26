#include <iostream>

using namespace std;

void characterFormatting(string in, string ans)
{
        if(in.size() == 0)
        {
                cout<<ans<<endl;
                return;
        }

        char ch = in[0];
        string ros = in.substr(1);

        if(ch == ros[0])
        {
                characterFormatting(ros, ans+ch+"*");
        }
        else
        {
                characterFormatting(ros, ans +ch);
        }
}

int main()
{
    string in;
    cin>>in;

    characterFormatting(in,"");

    return 0;
}

