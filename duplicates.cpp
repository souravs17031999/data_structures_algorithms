// @author sourav kumar , 19-01-2019

// program for removing dupliactes

#include<iostream>
using namespace std;

void rem(int arr[], int j, int &n){
    // Delete the current duplicate element
                for(int k = j; k <= n-2; k++) 
                {
                    arr[k] = arr[k + 1];
                }
 
                //Decrement size after removing duplicate element
                n--;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i <= n-1; i++){
        cin >> arr[i];
    }
    for(int i = 0; i <= n-1; i++)
    {
        for(int j = i+1; j <= n-1; j++)
        {
            //If any duplicate found */
            if(arr[i] == arr[j])
            {
                rem(arr,j,n);
 
                // If shifting of elements occur then don't increment j
                j--; // if j-- is not put here then only one dupliacte of each kind can be removed because then the value of j will chnage but if applied the value of j remains same.
            }
        }
    }
    for(int i = 0; i <= n-1; i++){
        cout << arr[i] <<" ";
    }
    
}