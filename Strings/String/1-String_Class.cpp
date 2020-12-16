#include<iostream>
#include<string>
using namespace std;

int main(){

	// String Init

	string s0;
	string s1("Hello");

	string s2 = "Hello World";
	string s3(s2);

	string s4 = s3;

	char a[] = {'a', 'b', 'c','\0'};
	string s5(a);

	cout<<s0<<endl;
	cout<<s1<<endl;
	cout<<s2<<endl;
	cout<<s3<<endl;
	cout<<s4<<endl;
	cout<<s5<<endl;


	// s0.empty()
	if(s0.empty()){
		cout<<"s0 is an empty string"<<endl;
	}

	// Append
	s0.append("I love C++");
	cout<<s0<<endl;
	s0 = s0 + " and Python";
	cout<<s0<<endl;


	// Remove
	cout<<s0.length()<<endl;
	s0.clear();
	cout<<s0.length()<<endl;


	// Compare the strings
	s0 = "Apple";
	s1 = "Mango";
	cout<<s0.compare(s1)<<endl;
	cout<<s1.compare(s0)<<endl;
	cout<<s1.compare(s1)<<endl;    	// Returns an integer -> equal to 0, > 0 or < 0


	// Overloaded Operator Operators
	if(s1 > s0){
		cout<<"Mango is lexicographically greater than Apple"<<endl;
	}


	cout<<s1[0]<<endl;


	// Find Substrings
	string s = "I want to have apple juice";
	int idx = s.find("apple");
	cout<<idx<<endl;


	// Remove a word from the string
	string word = "apple";
	int len = word.length();
	s.erase(idx, len);
	cout<<s<<endl;


	// Iterate over all the characters in the string

	//1. For loop
	for(int i=0;i<s1.length(); i++){
		cout<<s1[i]<<":";
	}
	cout<<endl;


	//2. Iterator
	for(auto it=s1.begin(); it!=s1.end(); it++){
		cout<<(*it)<<"->";
	}
	cout<<endl;

	//3. For Each Loop
	for(auto x:s1){
		cout<<x<<".";
	}
	cout<<endl;

	return 0;
}