// program to rotate the array towards right (clockwise)
// @author sourav kumar , 26-01-2019
#include <iostream>
using namespace std;


// function for rotating elements one by one 
void array_right_rotate(int arr[], int &n){
    int temp = arr[n-1];   // saving the last element as a temp var
    for(int i = n-2; i >= 0; i--){  // now transversing from last to first and shifting each by one index
        arr[i+1] = arr[i];
    }
    arr[0] = temp;  // finally assigning last one to first 
}

int main(void){
    int n,k;
    cout << "enter the size of array: " << endl;
    cin >> n;
    cout << "enter no of rotations: " << endl;
    cin >> k;
    int arr[n];
	// user input elements into array 
    for(int i = 0; i <= n-1; i++){
        cin >> arr[i];
    }
	// calling array_right_rotate for each time shifting 
    for(int i = 0; i <= k-1; i++){
        array_right_rotate(arr,n);
    }
	// displaying the array 
    for(int i = 0; i <= n-1; i++){
        cout << arr[i] << " ";
    }
}
