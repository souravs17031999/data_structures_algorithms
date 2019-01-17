/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<iostream>
using namespace std;

void fib(int f_arr[], int n){
    f_arr[0] = 0;
    f_arr[1] = 1; 
    for(int i=0; i<=n-3; i++){
        f_arr[i+2] = f_arr[i+1] + f_arr[i];
    }
    for(int i=0; i<=n-1; i++){
        cout<<f_arr[i]<<" ";
    }
}

int main()
{
    int n;
    cin>>n;
    if(n>=0){
        int f_arr[n];
        fib(f_arr,n);}
    else{
        cout<<"memory error due to wrong value of size";}    

    return 0;
}
