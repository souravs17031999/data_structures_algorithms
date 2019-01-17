// program for merging two arrays , in 0(n)

#include<iostream>
using namespace std;

int main(){
    int m;
    int n;
    cin>>m>>n;
    int arr1[m];
    int arr2[n];
    for(int i = 0; i <= m-1; i++){
        cin >> arr1[i];
    }
    for(int i = 0; i <= n-1; i++){
        cin >> arr2[i];
    }
    int k = m + n;
    int arr3[k];
    
    for(int i = 0; i <= m-1; i++){
        arr3[i] = arr1[i];
    }
    int c = 0;
    for(int i = m; i <= k-1; i++){
        arr3[i] = arr2[c];
        c = c + 1;  // we need it to put some antother variable because arr3 and arr2 are taking different vaues like arr3 goes from 4 to 7 but arr2 goes from 0 to 3.
       
    }
    for(int i = 0; i <= k-1; i++){
        cout << arr3[i] <<" ";
    }
}