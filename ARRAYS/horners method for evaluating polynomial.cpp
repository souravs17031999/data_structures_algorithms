// program for implementing horners method for evaluating polynomial
// horners method is based on the idea that the polynomial can be evaluated by 
// simulataneously multiplying x with old value of y and then adding it with new given coeff
 // @author sourav kumar   , 30 
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
