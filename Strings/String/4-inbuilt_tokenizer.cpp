#include<iostream>
#include<cstring>
using namespace std;

char *mystrtok(char *str, char delim){

	// String and static char actsas delimiter
	static char*input = NULL;
	if(str!=NULL){
		// We are making the first call
		input = str;
	}

	// Check here - Base Case after the final token has been returned 
	if(input == NULL)
		return NULL;


	// Start extracting tokens and store them in an array
	char *output= new char[strlen(input)+1];

	int i=0;

	for( ; input[i]!='\0';i++){
		if(input[i]!=delim){
			output[i] = input[i];
		}
		else{
			output[i] = '\0';
			input = input + i + 1;
			return output;
		}
	}

	// Corner Case
	output[i] = '\0';
	input = NULL;
	return output;

}

int main(){

	char str[] = "This, is a rainy, day";

	char *ptr = mystrtok(str, ',');

	cout<<ptr<<endl;

	while(ptr!=NULL){
		ptr = mystrtok(NULL, ',');
		cout<<ptr<<endl;
	}



	return 0;
}
