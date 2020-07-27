#include <iostream>
#include<vector>

using namespace std;

int main()
{
    //Initialize a Vector
    vector<int> a;
    vector<int> b(10);      //Create a vector with 10 elements in the array and initialize every element with 0
    vector<int> c(5, 10);       //Vector will have 5 elements with value 10 of each element
    vector<int> d(c.begin(), c.end());      //Copy all the elements of vector c to vector d
    vector<int> e{1,2,3,4,5};       //Initialize a vector with values;

    //Iterating over the vector

    for(int i=0;i<b.size();i++)
    {
            cout<<b[i]<<" ";
    }
    cout<<endl<<endl;

    for(auto it=c.begin(); it!=c.end(); it++)       // Using Iterator. Iterator behaves like a pointer and is defined it the vector class. vector<int> :: iterator can be used instead of auto
    {
            cout<<(*it)<<" ";
    }
    cout<<endl<<endl;

    for(int x: e)       //Using for each loop
    {
            cout<<x<<" ";
    }
    cout<<endl<<endl;

    //Input element from the user
    int n;
    cin>>n;

    cout<<endl<<"Enter elements of vector"<<endl;
    for(int i=0;i<n;i++)
    {
            int no;
            cin>>no;
            a.push_back(no);
    }

    cout<<endl<<"Elements of vector a are"<<endl;
    for(auto x: a)
    {
            cout<<x<<" ";
    }

    cout<<endl<<endl;

    //Difference between initialized vector and the vector with input taken from user

    //The size and capacity of vector with input taken from user will be different because elements are added in the array using push_back which
    //expands the size of vector when vector becomes full. Thus after, the addition of 4th element, the vector expands its size to 8, that means the capacity of vector is now 8
    cout<<"Size of vector a is "<<a.size()<<endl;
    cout<<"Capacity of vector a is "<<a.capacity()<<endl<<endl<<endl;

    //The size and capacity of initialized vector will be same because the vector knows with how space is to be taken to accomodate all the elements of the vector. Hence, the
    //vector is created with that much amount of capacity only
    cout<<"Size of vector b is "<<d.size()<<endl;
    cout<<"Capacity of vector b is "<<d.capacity()<<endl;



    return 0;
}
