// program for quick sort using arrays 
// @ author sourav kumar , 06-03-2019
// time complexity in worst case is O( n * n ) where n is length of array , average case is more often looked - O( n * lg(n) ) 
#include <iostream>
using namespace std;
// function to partition the array in such a way so that all the elements smaller than pivot are left to it , and greater are right to it (order doesn't matter)
 
int partition(int arr[], int start, int end){
    int pivot = arr[end];   // set pivot as last element 
    int p_index = start;    // set partition index as start initially
	// transversing the segment of array to be arranged in such a way that pivot is set at its correct position 
    for(int i = start; i <= end - 1; i++){     
        if(arr[i] <= pivot){   // now if any element is less than pivot , then swap with p index element and finally p index will point to correct position of pivot 
            swap(arr[i], arr[p_index]);
            p_index++;     // increment p_index only when swap is done 
        }
    }
    swap(arr[p_index], arr[end]);    // finally swap the element at p_index with the pivot element which is at last 
    return p_index;                  // return the index of correct position of pivot   
}
void quick_sort(int arr[], int start, int end){
    if(start < end){     /* run only when start is less than end and stop when start == end when only one element is present is segment or when start > end 
	when the segment required is invalid */
    int p_index = partition(arr, start, end);   // getting the correct position of pivot 
    quick_sort(arr, start, p_index - 1);      // now sorting the left segment of pivot 
    quick_sort(arr, p_index + 1, end);        // sorting the right segment of pivot 
	}
}
int main(void){
    int arr[7] = {1, 4, 1, 2, 7, 5, 2}; 
    quick_sort(arr, 0, 6);
    for(int i = 0; i <= 6; i++){
        cout << arr[i] << " ";
    }
	// 1 1 2 2 4 5 7 
}
