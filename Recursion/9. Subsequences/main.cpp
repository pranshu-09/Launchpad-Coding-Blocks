#include <iostream>

using namespace std;

void subsequences(char in[], char out[], int i, int j)
{
        if(in[i]=='\0')
        {
                out[j] = '\0';
                cout<<out<<endl;
                return;
        }

        out[j] = in[i];

        subsequences(in,out, i+1, j+1);
        subsequences(in, out, i+1, j);

}

void subsequences2(string in, string out)
{
        if(!in.size())
        {
                cout<<out<<endl;
                return;
        }

        char ch = in[0];

        subsequences2(in.substr(1), out + ch);
        subsequences2(in.substr(1), out);

}

int main()
{

//    char in[100], out[100];
//    cin>>in;
//
//    subsequences(in,out,0,0);

    string in;
    cin>>in;

    subsequences2(in,"");

    return 0;
}
