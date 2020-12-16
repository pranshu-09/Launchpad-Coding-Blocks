#include<iostream>
#include<cstring>
using namespace std;

int main(){

	int n;
	cin>>n;

	char a[1000];
	char largest[1000];

	int len=0;
	int largest_length=0;

	cin.get();		// This is added because when we press enter after pressing enter after inputing n, an empty string would be read and we need to avoid it

	for(int i=0;i<n;i++){
		cin.getline(a, 1000);

		len = strlen(a);

		if(len > largest_length){
			largest_length = len;
			strcpy(largest, a);	
		}
	}

	cout<<largest<<" and size of largest string is "<<largest_length<<endl;

}
