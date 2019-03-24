// program to check if a array contains a pair in a array of integers
// @author sourav kumar , 24-03-2019
// time complexity is average 0(n*lg(n))
#include <bits/stdc++.h>
using namespace std;
int check_sum(int arr[], int n, int sum){
    sort(arr, arr + n);
    int l = 0;
    int r = n - 1;
    while(l < r){
        if(arr[l] + arr[r] == sum){
            return 1;
        }
        else if((arr[l] + arr[r]) < sum){
            l++;
        }
        else{
            r--;
        }
    }
    return -1;
}
int main(void){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    cout << check_sum(arr, 10, 8);
    
}
