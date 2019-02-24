// program for output for kth smallest element in a given array as user input 
// implemented in 0(n*log(n)) 

#include <bits/stdc++.h>
using namespace std;
// function for output for kth smallest element given array as argument and also value of k 
void k_small(int arr[], int n, int k){
    sort(arr, arr+n);  // using in-built stl function sort() of 0(n*lg(n)) complexity
    cout << arr[k-1] << endl;   // output the required element 
}
// driver main function for testing out other functions 
int main(void){
    int t,n,k;
        cin >> n;
        int arr[n];
		// taking user input of elements of array 
        for(int i = 0; i <= n-1; i++){
            cin >> arr[i];
        }
        cin >> k;
		// calling the required function 
        k_small(arr,n,k);   
}


