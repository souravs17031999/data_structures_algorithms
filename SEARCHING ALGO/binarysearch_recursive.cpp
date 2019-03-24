// program for implementing binary search through recursive approach (divide and conquer technique)
// time complexity is 0(log(n))
// T(n) = T(n/2) + c   (recurrence equation)
// @author sourav kumar, 24-03-2019
#include <iostream>
using namespace std;
int binary_search(int arr[], int l, int r, int key){
    int mid = (r + l) / 2;
    if(arr[mid] == key){
        return mid;
    }
    if(key < arr[mid]){
        return binary_search(arr, l, mid - 1, key);
    }
    else{
        return binary_search(arr, mid + 1, r, key);
    }
}
int main(void){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    cout << binary_search(arr, 0, 9 ,10);
    
}
