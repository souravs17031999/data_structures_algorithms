// @author sourav kumar , 22-01-2019
// program for reversing the element

#include <iostream>
using namespace std;

void swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}
void reversal(int arr[],int &n){
    for(int i = 0; i <= (n/2)-1; i++){
            swap(arr[i],arr[n-i-1]);
    }
}
int main(void){
    int n;
    cin >> n;
    int arr[n];
    cout << "array before reversal:" << endl;
    for(int i = 0; i <= n-1; i++){
        cin >> arr[i];
    }
    for(int i = 0; i <= n-1; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    reversal(arr,n);
    cout << "array after reversal: " << endl;
    for(int i = 0; i <= n-1; i++){
        cout << arr[i] << " ";
    }
}
