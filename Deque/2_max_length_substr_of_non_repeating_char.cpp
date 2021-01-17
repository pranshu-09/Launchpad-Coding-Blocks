#include<iostream>
#include<cstring>
using namespace std;

int max_subarray(char str[], int n) {

	int curr_len = 1, max_len = 1;

	// Array to store index of the characters
	int visited[256];

	for (int i = 0; i < 256; i++)
		visited[i] = -1;


	// Operation for 1st elem
	visited[str[0]] = 0;

	for (int i = 1; i < n; i++) {

		int last_occur = visited[str[i]];


		//Expansion -> Current element is not present in the window
		if (last_occur == -1 or i - curr_len > last_occur) {			// If it is the first occurence of elem or elem is not present in the current window
			curr_len++;
			// max_len = max(max_len, curr_len);
		}

		// If we have to shrink the window
		else {

			if (curr_len > max_len) {
				max_len = curr_len;
			}
			curr_len = i - last_occur;
		}

		//Update the visited of current index
		visited[str[i]] = i;
	}

	max_len = max(max_len, curr_len);

	return max_len;
}

int main() {

	char str[] = "abccdefgh";
	int n = strlen(str);

	cout << max_subarray(str, n);

	return 0;
}