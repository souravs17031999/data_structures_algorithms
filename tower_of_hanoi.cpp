// program for implementing logic for solving tower of hanoi 
// @author sourav kumar , 06-03-2019
#include <iostream>
using namespace std;
// function for implementing the logic 
void tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod){
	// if only one disc left, then simply put it from_rod to to_rod 
    if(n == 1){
        cout << "disk 1 moved from " << from_rod << " to " << to_rod << endl;
        return;
    }
	// call these recursive calls till all the disc above the last one has been moved to middle rod 
    tower_of_hanoi(n-1, from_rod, aux_rod, to_rod);
    cout << "disk " << n << " moved from " << from_rod << " to " << to_rod << endl;
	// now call these recursive calls till all the rod has been moved from middle rod to last rod above the last disc  
    tower_of_hanoi(n-1, aux_rod, to_rod, from_rod);
}
// main driver function 
int main(void){
    int n = 4;
    tower_of_hanoi(n, 'A', 'B', 'C');
}
