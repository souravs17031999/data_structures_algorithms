//program for bubble sort acending order , time complexity is 0(n*n) for the worst case and 0(n) for the best case.

#include <iostream>
using namespace std;

int swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}

int bub_sort(int arr[], int n){
    int flag;
	for(int i=0; i<=n-2; i++){
		flag = 0;
        for(int j=0; j<=n-i-2; j++){
            if(arr[j+1]<arr[j]){
                swap(arr[j],arr[j+1]);
				flag = 1;
            }
        }
		if(flag==0){
		break;}
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
