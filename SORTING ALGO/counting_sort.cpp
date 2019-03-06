// program for counting sort using arrays 
/* logic is to simply first maintain a count array for keeping the occurence of each of the character in the array and then now the index of the count array is already
   already sorted. Then , we need to transverse this array and copy the index values as no of times as the value it contains at its index into some another array 
   which will be sorted as we will finish transversing the count array  */
// time complexity is O( n + k ) where n is the length of original array and k is the length of temp count array 
// @author sourav kumar , 06-03-2019   
#include <iostream>
using namespace std;
//function for implementing counting sort 
void count_sort(int arr[], int n){
	// firstly find max , as no element will occur more than the maximum value in the array 
    int max = arr[0];
    for(int i = 0; i <= n-1; i++){
        if(max < arr[i]){
            max = arr[i];
        }
    }
    int k = max;
	// hence , intialising a count array of size max + 1 as all 0's
    int count[k + 1];
    for(int i = 0; i <= k; i++){
        count[i] = 0;
    }
	// now assinging the occurence of all characters in the array corresponding to their respective indices 
    for(int i = 0; i <= n-1; i++){
        count[arr[i]]++;
    }
	// now this will be sorted array when we finish 
    int sorted_array[n];
    int temp = 0;
	// transversing our count array to take the indices which is our original elements to be sorted and the values which will be copied that no of times 
    for(int i = 0; i <= k; i++){
        int t = count[i];    // no of times the element (index i) will be copied is t 
        while(t--){
            sorted_array[temp] = i;   // copying the element in sorted order 
            temp++;   // incrementing the sorted array index 
        }
    }
	// printing out sorted array 
    for(int i = 0; i <= n-1; i++){
        cout << sorted_array[i] << " ";
    }
}
// main driver function to test other functions 
int main(void){
    int arr[7] = {1, 4, 1, 2, 7, 5, 2}; 
    count_sort(arr, 7);
    // 1 1 2 2 4 5 7 
}
