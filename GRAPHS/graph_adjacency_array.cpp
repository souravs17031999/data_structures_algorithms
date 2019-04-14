#include <bits/stdc++.h>
#define nodes 10
using namespace std;
void addedge(int arr[nodes][nodes], int u, int v){
    if(u >= nodes || v >= nodes){
        return;
    }
    arr[u][v] = 1;
}
void printgraph(int arr[10][10]){
    for(int i = 0; i <= 9; i++){
        for(int j = 0; j <= 9; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
int main(void){
    // Your code here
    int arr[nodes][nodes];
    memset(arr, 0, sizeof(arr));
    addedge(arr, 0, 1);  
    addedge(arr, 3, 1);
    addedge(arr, 9, 7);
    addedge(arr, 900, 90);   // simply return as is invalid location 
    printgraph(arr);
}
