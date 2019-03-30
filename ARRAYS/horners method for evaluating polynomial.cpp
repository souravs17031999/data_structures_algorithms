#include<iostream>
using namespace std;
int main()
{
int arr[4] = {2, -6, 2, -1};
int x = 3;
int y = arr[0];
for(int i = 1; i <= 3; i++){
    y = arr[i] + x*y;
}
cout << y;
}