// program for merging two sorted arrays 
// @author sourav kumar , 06-03-2019
#include <iostream>
using namespace std;
// function for merging arrays [ note the two arrays here are already sorted and we have to just merge them]
void merge(int arr1[], int n1, int arr2[], int n2){
    int t = n1 + n2;
    int arr3[t];
    int i = 0;
    int j = 0;
    int k = 0;
	/* logic is to simply transverse both the arrays simultaneously and checking which one is smaller and the smaller one is copied to the new array one by one and 
	   and for this we need three variable to keep track of all three arrays simultaneously */
    while(i <= n1 && j <= n2){
        if(arr1[i] <= arr2[j]){   // if the left subarray contains the smaller element then copy it and increment its index variable (i)
            arr3[k] = arr1[i];
            i++;
        }
        else{
            arr3[k] = arr2[j];    // if the right subarray contains the smaller element then copy it and increment its index variable (j)
            j++;
        }
        k++;      // increment the new array index variable k so that the element should be copied 
    }
    k--;          // since the k is now pointing towards the next space so decrementing it 
    /* now when the above loop ends , one of the subarrays will contains some left overs in the array which will now be handled 
	   since the subarrays are already sorted , then we have to just copy the leftover part of whichever the subarray is */
	while(i < n1){      
        arr3[k] = arr1[i];     // if leftovers are from left subarray then copy them one by one 
        i++;
        k++;
    }
    while(j < n2){ 
        arr3[k] = arr2[j];     // if leftovers are from right subarray then copy them one by one 
        j++; 
        k++;
    }
    // printing the merged array
    for(int i = 0; i <= t - 1; i++){
        cout << arr3[i] << " ";
    }
}
// driver main function for testing out other functions 
int main(void){
    int n1 = 4;
    int n2 = 4;
    int arr1[4] = {1,2,4,6};
    int arr2[4] = {3,5,7,8};
    merge(arr1, n1, arr2, n2);
	// 1 2 3 4 5 6 7 8 
}
