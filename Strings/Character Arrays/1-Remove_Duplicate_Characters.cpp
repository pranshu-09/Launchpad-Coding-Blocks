#include<iostream>
#include<cstring>
using namespace std;

void final_string(char str[]){

	int l = strlen(str);

	int j=0;

	for(int i=0;i<l;i++){

		if(str[i] != str[j]){
			j++;
			str[j] = str[i];
		}

	}

	str[j+1] = '\0';
}


int main(){

	char str[100];
	cin>>str;

	final_string(str);

	cout<<str;

	return 0;
}