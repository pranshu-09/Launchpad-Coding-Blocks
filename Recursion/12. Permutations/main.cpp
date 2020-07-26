#include <iostream>

using namespace std;

void permutations(char in[], int i)
{
        if(in[i]=='\0')
        {
                cout<<in<<endl;
                return;
        }

        for(int j=i; in[j]!='\0'; j++)
        {
                swap(in[i], in[j]);
                permutations(in, i+1);

                //BackTracking to change the updated array into its original form
                swap(in[i], in[j]);
        }
}

void printPermutations(string s, string out)
{
        if(s.size()==0)
        {
            cout<<out<<endl;
            return;
        }

        for(int i=0;i<s.size();i++)
        {
                char ch = s[i];
                string ros = s.substr(0,i) + s.substr(i+1);

                printPermutations(ros, out+ch);
        }
}

int main()
{
    char in[50];   //Or string in;
    cin>>in;

//    permutations(in,0);

    printPermutations(in,"");

    return 0;
}
