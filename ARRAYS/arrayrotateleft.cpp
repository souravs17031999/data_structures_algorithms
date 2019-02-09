// program to rotate the array towards left (anti-clockwise)
// @author sourav kumar , 26-01-2019
#include <iostream>
using namespace std;


// function for rotating elements one by one 
void array_right_rotate(int arr[], int &n){
    int temp = arr[0];   // saving the first element as temp var 
    for(int i = 0; i <= n-2; i++){  // now transversing from first to last shifting each one to the left by one index
        arr[i] = arr[i+1];
    }
    arr[n-1] = temp;  // now finally assinging first one to the last one for each shift
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
        array_right_rotate(arr, n);
    }
	// displaying the array 
    for(int i = 0; i <= n-1; i++){
        cout << arr[i] << " ";
    }
	
}
