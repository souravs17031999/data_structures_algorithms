// program for selection sort using arrays 
#include <iostream>
using namespace std;
/* logic is to divide the array into two parts every time we iterate through the loop and select the first element as min and trasnverse the other half to find the 
    minimum and then swap those two and continue this until every element is sorted */
void selection_sort(int arr[], int &n){
    for(int i = 0; i <= n-2; i++){  // transversing the array 
        int s_index = i;    // setting the first element of array as minimum 
        for(int j = i + 1; j <= n-1; j++){   //transverse the sub-array leaving the other half which is already sorted    
            if(arr[s_index] > arr[j]){    // now compare for if any element is more less than minimum , in that case , update the minimum 
                s_index = j;    // set the index where that minimum occured element is in the array 
                
            }
        }
        
        swap(arr[s_index], arr[i]);   // now swap those two ( one is assumed min , and other is updated min)
        
    }
}
// driver main function for testing other functions 
int main(void){
    int arr[5] = {64, 25000, 1234, 221, 11};
    int n =5;
    selection_sort(arr,n);
    for(int i = 0; i <= 4; i++){
        cout << arr[i] << " ";
    }
    
}
