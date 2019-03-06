// program for implementing merge sort using arrays 
/* logic is to simply go on dividing the arrays into equal lengths of two sub arrays and then merging it while simulatenously sorting 
   when only two elements are left */
// time complexity is O(n * lg(n)) and space complexity is O(n) where n is the length of the array 
// @author sourav kumar, 06-03-2019   
#include <iostream>
using namespace std;
// function for implementing first breaking the array into two halves and merging two sorted arrays 
void merge(int arr3[], int start, int middle, int end){
	// finding the size of left and right sub array 
    int n1 = (middle - start) + 1;
    int n2 = end - middle;
	// creating two temporary sub arrays 
    int arr1[n1];
    int arr2[n2];
	// now copying the elemnts from original arrays to temporary sub arrays
    for(int i = 0; i <= n1-1; i++){
        arr1[i] = arr3[start + i];
    }
    for(int i = 0; i <= n2-1; i++){
        arr2[i] = arr3[middle + 1 + i];
        
    }
    // intialising three variables correspondingly - one for left subarray (i) , another for right subarray (j) , and last (k) for original array 
    int i = 0;   // Initial index of left subarray
    int j = 0;   // Initial index of right subarray 
    int k = start;  // setting the initial index of merged subarray 
	// from here on , the logic is same as when we merge two sorted arrays
	// transverse all through the both arrays and simulatenously checking which one is smaller , and then copying the smaller one to the main array overwriting it
    while(i <= n1 && j <= n2){
        if(arr1[i] <= arr2[j]){
            arr3[k] = arr1[i];
            i++;
        }
        else{
            arr3[k] = arr2[j];
            j++;
        }
        k++;
    }
    k--;
	// for leftovers in any of the subarray 
    while(i < n1){
        arr3[k] = arr1[i];
        i++;
        k++;
    }
    while(j < n2){
        arr3[k] = arr2[j];
        j++;
        k++;
    }
}
// function for merge sort 
void merge_sort(int arr3[], int start, int end){
    if(start < end){    // it will break only when one element is left in the array (sub-array) or when the segment is invalid 
        int middle = start + (end - start) / 2;     
        merge_sort(arr3, start, middle);   // sorting left half of array 
        merge_sort(arr3, middle + 1, end); // sorting right half of array 
        merge(arr3, start, middle, end);   // merging both the above halves created
    }
}
int main(void){
    int arr[10] = {6,2,3,1,9,10,15,13,12,17};
    int n = 10;
    merge_sort(arr, 0, n-1);
    for(int i = 0; i <= n-1; i++){
        cout << arr[i] << " ";
    }
	// 1 2 3 6 9 10 12 13 15 17 

}
