#include <iostream>

using namespace std;

void printNumber(int n)
{

        if(n==0)
            return;

        int num = n%10;
        printNumber(n/10);

        switch(num)
        {
                case 0 : cout<<"zero ";
                               break;
                case 1 : cout<<"one ";
                               break;
                case 2 : cout<<"two ";
                               break;
                case 3 : cout<<"three ";
                               break;
                case 4 : cout<<"four ";
                               break;
                case 5 : cout<<"five ";
                               break;
                case 6 : cout<<"six ";
                               break;
                case 7 : cout<<"seven ";
                               break;
                case 8 : cout<<"eight ";
                               break;
                case 9 : cout<<"nine ";
                               break;
        }
}

string spelling[] = {"zero","one","two","three", "four", "five", "six", "seven", "eight", "nine"};

void print_using_strings(int n)
{
        if(n==0)
            return;

        int num = n%10;
        printNumber(n/10);
        cout<<spelling[num]<<" ";
}

int main()
{
    int n;
    cin>>n;

    printNumber(n);
    cout<<endl;
    print_using_strings(n);
    return 0;
}
