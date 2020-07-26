//Count Board path/ Dice Problem. Determine steps required to reach the end, when it moves by no. that is displayed on the dice
#include <iostream>

using namespace std;

int count=0;

void countBoardPath(int i, int n)
{
        if(i == n)
           {
                count++;
                return;
           }

        if(i>n)
            return;

        for(int d=1;d<=6;d++)
        {
                 countBoardPath(i+d, n);
        }

}

int countBoardPath2(int start,int end){
	//Base Case
	if(start==end){
		return 1;
	}

	if(start>end){
		return 0;
	}

	//Recursive Case
	int count = 0;

	for(int dice = 1;dice<=6;dice++){
		count+= countBoardPath2(start+dice,end);
	}

	return count;
}

void printBoardPath(int start, int end, string ans)
{
        if(start == end)
        {
                cout<<ans<<endl;
                return;
        }

        if(start>end)
            return;

        for(int d=1;d<=6;d++)
        {
                char ch = d + '0';
                printBoardPath(start+d, end, ans+ch);
        }

}


int main()
{
    int n;
    cin>>n;

    printBoardPath(0,n,"");

    cout<<"Paths possible are "<<countBoardPath2(0,n);

//    cout<<count;

    return 0;
}
