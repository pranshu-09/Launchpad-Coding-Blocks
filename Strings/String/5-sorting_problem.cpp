#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

string extract_string_at_key(string str, int key){

	// Using strtok
	char *s = strtok((char *)str.c_str(), " ");		// Converting string datatype into char*

	while(key>1){
		s = strtok(NULL, " ");
		key--;
	}

	return (string)s;
}

int convert_to_int(string s){
	int ans = 0;
	int p=1;

	for(int i=s.length()-1; i>=0; i--){
		ans = ans + ((s[i]-'0')*p);
		p = p*10;
	}

	return ans;
}

bool numeric_compare(pair<string, string> a, pair<string, string> b){
	
	string val1 = a.second;
	string val2 = b.second;

	return convert_to_int(val1) < convert_to_int(val2);
}

bool lexico_compare(pair<string, string> a, pair<string, string> b){
	return a.second < b.second;	
}

int main(){

	int n;
	cin>>n;

	cin.get();

	string ans[100];

	for(int i=0;i<n;i++){
		getline(cin, ans[i]);
	}

	int key;
	cin>>key;

	string reversal, ordering;
	cin>>reversal>>ordering;


	// Step 1 -> Extract the key from the input strings and store them in a pair along with the original string
	pair <string, string> strPair[100];

	for(int i=0;i<n;i++){
		strPair[i].first = ans[i];
		strPair[i].second = extract_string_at_key(ans[i], key);
	}


	// Step 2 -> Sorting
	if(ordering == "numeric"){
		sort(strPair, strPair+n, numeric_compare);
	}
	else{
		sort(strPair, strPair+n, lexico_compare);
	}

	// Step 3 -> Reversal
	if(reversal == "true"){
		for(int i=0;i<n/2;i++){
			swap(strPair[i], strPair[n-i-1]);
		}
	}

	for(int i=0;i<n;i++){
		cout<<strPair[i].first<<endl;
	}

	return 0;
}