// Check whether the given string is anagram.
// 2 strings are anagram when the characters in the strings are same, i.e., they should have same no. of characters repeating same  no. of times.

#include<iostream>
#include<bitset>
#include<algorithm>
using namespace std;

int main()
{
	// string a = "cat";
	// string b = "acp";

	// // Method 1
	// bool isAnagram = false;

	// if(a.length() == b.length())
	// {
	// 	for(int i=0;i<a.size();i++)
	// 	{
	// 		char ch = a[i];
	// 		isAnagram = false;

	// 		for(int j=0;j<b.length();j++)
	// 		{
	// 			if(b[j] == ch)
	// 			{
	// 				isAnagram = true;
	// 				break;
	// 			}
	// 		}

	// 		if(!isAnagram)
	// 			break;
	// 	}
	// }

	// if(isAnagram)
	// 	cout<<"Strings are anagram"<<endl;
	// else
	// 	cout<<"Strings are not anagram"<<endl;

	// Problem with this method is that this method rule out the fact that there might be repeating characters in the strings. 
	// Example, If we take "aab" and "abc", it will predict that strings are anagram because all characters of string a will be matched with string b.
	// Moreover, this method works in O(N2) which is not optimised

	// Method 2
	// We can make a boolean array or bitset and check whether a particular character of b is visited or not

	// string a = "aab";
	// string b = "abx";

	// bitset< 32 > visited; 

	// bool isAnagram = false;

	// if(a.length() == b.length())
	// {
	// 	for(int i=0;i<a.size();i++)
	// 	{
	// 		char ch = a[i];
	// 		isAnagram = false;

	// 		for(int j=0;j<b.length();j++)
	// 		{
	// 			if(b[j] == ch and !visited[j])
	// 			{
	// 				visited[j] = 1;
	// 				isAnagram = true;
	// 				break;
	// 			}
	// 		}

	// 		if(!isAnagram)
	// 			break;
	// 	}
	// }

	// if(isAnagram)
	// 	cout<<"Strings are anagram"<<endl;
	// else
	// 	cout<<"Strings are not anagram"<<endl;


	// Method 3
	// Sort the strings and simply check if both the strings are equal are not

	string a = "aabc";
	string b = "bcaall";

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	if(a == b)
		cout<<"Strings are anagram"<<endl;
	else
		cout<<"Strings are not anagram"<<endl;


	// Method 4
	


	return 0;
}