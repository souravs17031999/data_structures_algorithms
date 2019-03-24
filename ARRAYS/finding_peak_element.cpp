// program for finding the peak element : that element which is relatively greater than its neighbours , that is it will be in somewhere or at the first or at the last
// using divide and conquer , time complexity is 0(log(n))
// otherwise can be also solved using linear search also in 0(n) [but that's not efficient]
// @author sourav kumar  , 24-03-2019
// logic is to apply similar approach to binary search , as if the middle element is the peak , then return it otherwise if the left one is greater than the mid , then 
// simply it means left half contains peak element and similarly for right half.
// so now  break the problem for that approapriate size and check for it.
#include <bits/stdc++.h>
using namespace std;
int peak_element(int arr[], int n, int l, int r){
    int mid = (l + r) / 2;
    if(mid == 0 || arr[mid - 1] < arr[mid] && arr[mid + 1] < arr[mid] || mid == n - 1){
        return arr[mid];
    }
    else if(mid > 0 && arr[mid - 1] > arr[mid]){
        return peak_element(arr, n, l, r - 1);
    }
    else{
        return peak_element(arr, n, l + 1, r);
    }
}
int main(void){
    int arr[7] = {10, 20, 30, 78, 78, 89, 90};
    cout << peak_element(arr, 7, 0, 6);
    // output : 90
}
