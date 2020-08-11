#include <iostream>
#include<bitset>
#include<vector>
#include<climits>

using namespace std;

int BinaryConcatenation(int x, int y)
{
    bitset<30> X(x), Y(y);

    string binX = X.to_string();
    string binY = Y.to_string();

    int idx1 = binX.find('1');
    binX = binX.substr(idx1);

    int idx2 = binY.find('1');
    binY = binY.substr(idx2);

    string binXplusY = binX + binY;
    string binYplusX = binY + binX;

    bitset<60> bin1(binXplusY);
    bitset<60> bin2(binYplusX);

    int sum1 = bin1.to_ulong();
    int sum2 = bin2.to_ulong();

    return sum1-sum2;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector<int> a;

        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            a.push_back(x);
        }

        int maxx = INT_MIN;

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int diff = BinaryConcatenation(a[i], a[j]);
                maxx = max(maxx, diff);
            }
        }

        cout<<maxx<<endl;
    }
	return 0;
}
