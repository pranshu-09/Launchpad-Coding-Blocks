#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Car
{
    public:
    string name;
    int x;
    int y;

    Car(string n, int x, int y)
    {
            name = n;
            this->x = x;
            this->y = y;
    }

    int distance()
    {
            return x*x + y*y;
    }

};

bool compare(Car A, Car B)
{
        int d1 = A.distance();
        int d2 = B.distance();

        if(d1==d2)
            return A.name < B.name;

        return d1 < d2;
}

int main()
{
    int n;
    cin>>n;

    vector<Car> v;

    for(int i=0;i<n;i++)
    {
            string name;
            int x, y;

            cin>>name>>x>>y;

            Car temp(name, x, y);

            v.push_back(temp);
    }

    sort(v.begin(), v.end(), compare);

    cout<<endl;

    for(auto x: v)
    {
            cout<<"Car-> "<<x.name<<" Distance-> "<<x.distance()<<" Coordinates-> ("<<x.x<<", "<<x.y<<")"<<endl;
    }

    return 0;
}
