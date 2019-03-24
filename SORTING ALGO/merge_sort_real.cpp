// implement merge sort to sort a array of numbers 
// time complexity is 0(n*lg(n))
// @author sourav kumar, 24-03-2019
#include <iostream>
using namespace std;
void merge(int arr3[], int start, int middle, int end){
    // finding the size of left and right sub array 
    int n1 = (middle - start) + 1;
    int n2 = end - middle;
	// creating two temporary sub arrays 
    int arr1[n1 + 1];
    int arr2[n2 + 1];
	// now copying the elemnts from original arrays to temporary sub arrays
    for(int i = 0; i <= n1-1; i++){
        arr1[i] = arr3[start + i];
    }
    for(int i = 0; i <= n2-1; i++){
        arr2[i] = arr3[middle + 1 + i];
        
    }
    // setting the last elment as very big number so that when compared to it , the leftovers element will alwasy be copied to the original array 
    arr1[n1] = 10000000;
    arr2[n2] = 10000000;
    int i = 0;
    int j = 0;
    // trasnversing so that element is copied to original array in sorted order
    for(int k = start; k <= end; k++){
        // if left one is smaller then it should come before
        if(arr1[i] <= arr2[j]){
            arr3[k] = arr1[i];
            i = i + 1;
        }
        // if right one is smaller then it should come now 
        else{
            arr3[k] = arr2[j];
            j = j + 1;
        }
    }
}
void merge_sort(int arr3[], int start, int end){
    if(start < end){
        int middle = start + (end - start) / 2;
        merge_sort(arr3, start, middle);
        merge_sort(arr3, middle + 1, end);
        merge(arr3, start, middle, end);
    }
}
int main(){
    int arr[6] = {120,45,1,55,23,67};
    merge_sort(arr,0,5);
    for(int i = 0; i <= 5; i++){
        cout << arr[i] << " ";
    }
}