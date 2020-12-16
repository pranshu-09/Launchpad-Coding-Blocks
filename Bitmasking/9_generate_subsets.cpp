#include<iostream>
#include<cstring>
using namespace std;

void filter_chars(int n, char a[]){

	int j=0;

	while(n > 0){

		int last_bit = n&1;

		if(last_bit){
			cout<<a[j];
		}

		j++;
		n = n>>1;
	}

}

void generate_subsets(char a[]){

	int n = strlen(a);

	for(int i=0;i<(1 << n); i++){
		filter_chars(i, a);
		cout<<endl;
	}

}

int main(){

	char a[100];
	cin>>a;

	generate_subsets(a);

	return 0;
}