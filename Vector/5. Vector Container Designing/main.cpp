#include <iostream>
#include "Vector.h"

using namespace std;

int main()
{
    Vector<char> v;

    v.push_back(71);
    v.push_back(72);
    v.push_back(73);
    v.push_back(74);
    v.push_back(75);

    v.pop_back();

    v.push_back(76);

    cout<<"Capacity " << v.capacity()<<endl;

    for(int i=0;i<v.size();i++)
    {
            cout<<v[i]<<" ";
    }

    return 0;
}
