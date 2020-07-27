#include <iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> d{1,2,3,4,5};

    //Insert element
    d.push_back(12);
    d.push_back(15);

    //Delete last element
    d.pop_back();

    //Insert element in the middle of the vector
    d.insert(d.begin()+3, 78);

    //Insert multiple elements(same values) in the middle of the vector
    d.insert(d.begin()+4, 4, -5);

    //Erase elements from the middle of the vector
    d.erase(d.begin()+3);

    //Erase multiple elements from the middle of the vector
    d.erase(d.begin()+3, d.begin()+7);

    //Determine the size of the vector
    cout<<d.size()<<endl;

    //Determine the underlying capacity of vector
    cout<<d.capacity()<<endl<<endl;

    //Resize the vector.
    //If resize parameter is greater than size of vector, zeros will be inserted at the end of the vector to match the resize parameter.
    //If resize parameter is less than size of vector, then elements from the last will be deleted
    d.resize(10);

    //Clear the vector
    d.clear();
    cout<<"Size after clearing vector "<<d.size()<<endl<<endl;

    //Check whether the vector is empty
    if(d.empty())
        cout<<"Vector is Empty"<<endl<<endl;

    d.push_back(10);
    d.push_back(20);
    d.push_back(30);

//    Get the first and last element of the vector
    cout<<d.front()<<endl;
    cout<<d.back()<<endl;

    for(int x: d)
        cout<<x<<" ";

    cout<<endl;

    //Reserve
    int n;
    cin>>n;

    vector<int> v;

    v.reserve(1000);        //If the elements of the vector exceeds 1000, only then the vector will double its size

    for(int i=0;i<n;i++)
    {
            int no;
            cin>>no;
            v.push_back(no);
    }

    for(int x: v)
        cout<<x<<" ";

    cout<<endl;

    return 0;
}
