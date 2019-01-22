@author sourav kumar , 22-01-2019 

// program to transpose a array 

#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int n = 4;
    int arr[4][4] = {{9, 13, 5, 2}, {1, 11, 7, 6}, {3, 7, 4, 1}, {6, 0, 7, 10}};  //initializing array
    // displaying the initial array
    for(int i = 0; i <= n-1; i++){  
        for(int j = 0; j <= n-1; j++){
        cout << arr[i][j] << " ";}
    
        cout << endl;
    }
    // the logic is to loop only through upper half triangular matrix or lower half , here i choose upper half as we need to 1,0 -> 0,1 otherwise if you choose entire array then 0,1 -> 1,0 and then again 1,0 -> 0,1 so no chnage
    for(int i = 0; i <= n-2; i++){    // looping over columns
        for(int j = i+1; j <= n-1; j++){   // looping over rows above the diagonal leaving the diagonal elements as it is not to be changed after transpose
            int temp = arr[i][j];  // swaping the values using temporary variable
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
    cout << "changed " << endl;
    // displaying the modified transposed array 
    for(int i = 0; i <= n-1; i++){  
        for(int j = 0; j <= n-1; j++){
        cout << arr[i][j] << " ";}
    
        cout << endl;
    }
    
}
