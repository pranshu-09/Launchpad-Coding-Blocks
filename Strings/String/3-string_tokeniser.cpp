#include<iostream>
#include<cstring>
using namespace std;

// char *strtol(char *s, char *delimiters)
// returns a token on each subsequent call
// on first call, function should be passed with string argument for 's'
// on subsequent call, we should pass the string argument as well

int main(){

	char str[] = "This is a rainy day";

	char *ptr = strtok(str, " ");

	cout<<ptr<<endl;

	while(ptr!=NULL){
		ptr = strtok(NULL, " ");
		cout<<ptr<<endl;
	}



	return 0;
}
