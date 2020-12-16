#include<iostream>
using namespace std;

// METHOD-1

//Time-Complexity - O(n)  Auxiliary-Space - O(d)
void rotateArrayMethod1(int arr[], int n, int d)
{
	int temp[d];

	for(int i=0;i<d;i++)
	{
		temp[i] = arr[i];
	}

	for(int i=d; i<n; i++)
	{
		arr[i-d] = arr[i];
	}

	for(int i=0;i<d;i++)
	{
		arr[n-d+i] = temp[i];
	}

	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
}


// METHOD-2

// Time-Complexity - O(n * d), Auxiliary-Space - O(1) 
void rotateByOne(int arr[], int n)
{
	int temp = arr[0];

	for(int i=1;i<n;i++)
		arr[i-1] = arr[i];

	arr[n-1] = temp;
}

void rotateArrayMethod2(int arr[], int n, int d)
{
	for(int i=0;i<d;i++)
	{
		rotateByOne(arr, n);
	}

	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
}



// METHOD-3

//Time-Complexity-O(n), Auxiliary-Space-O(1)
int return_gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
  
    else
        return return_gcd(b, a % b); 
} 



void rotateArrayMethod3(int arr[], int n, int d) 
{ 
    /* To handle if d >= n */
    d = d % n; 
    int g_c_d = return_gcd(d, n); 
    for (int i = 0; i < g_c_d; i++) 
    { 
        /* move i-th values of blocks */
        int temp = arr[i]; 
        int j = i; 
  
        while (1) 
        { 
            int k = j + d; 
            if (k >= n) 
                k = k - n; 
  
            if (k == i) 
                break; 
  
            arr[j] = arr[k]; 
            j = k; 
        } 
        arr[j] = temp; 
    }

	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";     
}


int main()
{
	int n, d;
	cin>>n>>d;

	int arr[100];

	for(int i=0;i<n;i++)
		cin>>arr[i];

	rotateArrayMethod1(arr, n, d);

	// leftRotate(arr, d, n);


}