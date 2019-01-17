#include <iostream>
using namespace std;

int swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

int bub_sort(int arr[], int n){
    for(int i=0; i<=n-2; i++){
        for(int j=0; j<=n-i-2; j++){
            if(arr[j+1]>arr[j]){
                swap(arr[j+1],arr[j]);
            }
        }
    }
    cout<<"after sorting :"<<endl;
    for(int i=0; i<=n-1; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
    int n, k, c=0;
    cout << "write the size of the array : " << endl;
    cin >> n;
    int arr[n];
    cout << "declare the elements of array: " << endl;
    for (int i = 0; i <= n - 1; i++)
        {
        cin >> arr[i];
        }
    cout << "the original array was: " << endl;
    for (int i = 0; i <= n - 1; i++)
        {
        cout << arr[i] << " ";
        }
    cout << endl;
    bub_sort(arr,n);
  return 0;
}}
