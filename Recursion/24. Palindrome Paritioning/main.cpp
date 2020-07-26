#include <iostream>

using namespace std;

bool isPalindrome(string s, int start, int end)
{
        while(start<=end)
        {
                if(s[start] != s[end])
                    return false;

                start++;
                end--;
        }

        return true;
}

int minCutsRequired(string s, int start, int end)
{
        if(start > end)
            return 0;

        if(start == end)
            return 0;

        if(end-start == 1)
            return s[start] != s[end];

    if(isPalindrome(s, start, end))
        return 0;

        int minValue = INT_MAX;

        for(int i=start; i<end; i++)
        {
                int leftCuts = minCutsRequired(s, start, i);
                int rightCuts = minCutsRequired(s, i+1, end);

                int currentAns = leftCuts + rightCuts + 1;

                minValue = min(minValue, currentAns);
        }

        return minValue;

}

int main()
{
    string in;
    cin>>in;

    cout<<"Minimum Cuts Required are "<<minCutsRequired(in, 0, in.size()-1);

    return 0;
}
