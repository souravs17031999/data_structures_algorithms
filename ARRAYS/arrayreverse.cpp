// @author sourav kumar , 22-01-2019
// program for reversing the element

#include <iostream>
using namespace std;
// function to swap two values.
void swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}
// function to reverse the array 
void reversal(int arr[],int &n){
    for(int i = 0; i <= (n/2)-1; i++){  // transversing till the half of array 
            swap(arr[i],arr[n-i-1]);   // swaping arr[i] and arr[n-i-1] like 0th and 5th for a 6-element array or like 1th and 4th.
    }
}
int main(void){
    int n;
    cin >> n;
    int arr[n];
    cout << "array before reversal:" << endl;  
    for(int i = 0; i <= n-1; i++){  // array initialization
        cin >> arr[i];
    }
    for(int i = 0; i <= n-1; i++){   // display array before reversal
        cout << arr[i] << " ";
    }
    cout << endl;
    reversal(arr,n);
    cout << "array after reversal: " << endl;
    for(int i = 0; i <= n-1; i++){    // display array after reversal
        cout << arr[i] << " ";
    }
}
