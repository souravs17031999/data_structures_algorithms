#include <iostream>
using namespace std;
void display(int arr[]){
    for(int i = 0; i <= 4; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
void insertion_sort(int arr[], int n){
    for(int i = 1; i <= n - 1; i++){
        int temp = arr[i];
        int j = i;
        while(j > 0 && arr[j - 1] > temp){
            arr[j] = arr[j - 1];
            j = j - 1;
        }
        arr[j] = temp;
        display(arr);
        
    }
    
}

int main(void){
    int arr[5] = {3,5,2,1,10};
    insertion_sort(arr,5);
    
}
