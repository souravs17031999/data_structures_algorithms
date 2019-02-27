// program for printing leaders of the array in the same order as in the array 
// actual program is tested on input size of 10^7 (array size) and element in the array of size (10^18) and time complexity is O(n) 
// @author sourav kumar , 27-02-2019

#include<bits/stdc++.h>
using namespace std;
// function for printing leaders in the array 
/* logic is to transverse from right to left as leaders are those elements which have are the greatest or equal to relative to their right elements , so we can assign
   max to last element (as it is always a leader) and then compare if there is any element greater than the last leader , then print it out , all in one pass 
*/
void leader(long long int arr[], long long int n){
    vector <long long int> v;  // vector for keeping all the track of leaders because we will get the reverse of what we actually want to print 
    long long int max = arr[n-1];
    v.push_back(max);
    for(long long int i = n - 2; i >= 0; i--){  
        if(arr[i] >= max){
            max = arr[i];
            v.push_back(max);   // pushing the leaders in the vector 
        }
    }
	// printing the leaders 
    for(long long int i = v.size()-1; i >= 0; i--){
        cout << v[i] << " ";
    }
    cout << endl;
    
}

int main()
 {
    long int t;
    cin >> t;
	// test cases
    while(t--){
        long long int n;
        cin >> n;
        long long int arr[n];
		// input array 
        for(long long int i = 0; i <= n-1; i++){
            cin >> arr[i];
        }
        leader(arr, n);
    }
	return 0;
}