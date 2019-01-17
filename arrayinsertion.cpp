#include <iostream>
using namespace std;

int main() {
    int n,k,p;
	cout<<"write the size of the array : "<<endl;
	cin>>n;
	int arr[n];
	cout<<"declare the elements of array: "<<endl;
	for(int i=0; i<=n-1; i++){
	    cin>>arr[i];
	}
	cout<<"the original array was: "<<endl;
	for(int i=0; i<=n-1; i++){
	    cout<<arr[i]<<" ";
	}
	cout<<endl;
	cout<<"enter the position of operation (assuming first index to be 0): "<<endl;
	cin>>k;
	cout<<"enter the element: "<<endl;
	cin>>p;
	for(int i=n; i>=k; i--){
	    arr[i+1] = arr[i];
	}
	arr[k]=p;
	for(int i=0; i<=n; i++){
	    cout<<arr[i]<<" ";
	}
	return 0;
}
