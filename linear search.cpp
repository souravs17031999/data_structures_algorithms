//program for linear search in c++ , time complexity is 0(n)

#include <iostream>
using namespace std;

int main (){
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
    for(int i = 0; i <= n-1; i++)
    {
        if(arr[i]==k)
        {
            c = c + 1;
            cout<<"element found at index "<<i<<endl;
        }
    }
    if(c>0)
    {
        cout<<"element found "<<c<<" times"<<endl;
        
    }
    else
    {
        cout<<"element not found"<<endl;
    }}
  return 0;
}
