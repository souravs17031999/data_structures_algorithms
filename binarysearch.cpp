//program for binary search , time complexity is O(log n)

#include <iostream>
using namespace std;

int bin_search(int l, int u, int n,int arr[], int k){
    int mid;
    while(l<=u){
        mid = (l+u)/2;
        if(arr[mid]==k){
            return mid;
        }
        if (k<arr[mid]){
            u=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return -1;
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
    cout<<"enter the searching element: "<<endl;
    cin>>k;
    cout<<bin_search(0,n-1,n,arr,k);
  return 0;
}}
