// program for implementing two stacks using one array [1...N]
// @author sourav kumar, 22-03-2019
/* there are two logics for this : first is two divide the array into two halves and start filling in accordingly in two halves as the two stack elements 
 but this is not memory efficient solution because it maybe the case that there is some space left in one part of array but the new elment can't be inserted due to
  overflow in another part.
  there exists a more efficient solution so that we can use two pointers top 1 and top2 to keep track as  both stack grows.
  we start from two extremums as top1 starts from leftmost index and top2 starts from rightmost index and the overflow occurs whenever both pointers collides.
  below is implementation of above logic.
  Push and Pop operations take 0(1) runtime.
*/
#include <iostream>
using namespace std;
#define MAX 10
class stacks{
  public:
    int top1 = -1;
    int top2 = MAX;
    int arr[1000];
    void push(int n, int x){
        if(top1 >= top2 - 1){
            return;
        }
        if(x == 1){
            top1++;
            arr[top1] = n;
        }
        else if(x == 2){
            top2--;
            arr[top2] = n;
        }
        
    }
    void pop(int x){
        if(top1 == -1 || top2 == MAX + 1){
            return;
        }
        if(x == 1){
            arr[top1] = NULL;
            top1--;
        }
        else if(x == 2){
            arr[top2] = NULL;
            top2++;
        }
    }
    void display(){
        if(top1 == -1 && top2 == MAX + 1){
            return;
        }
        for(int i = 0; i <= MAX - 1; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main(void){
    stacks s;
    s.push(1,1);
    s.push(2,1);
    s.push(3,1);
    s.push(4,1);
    s.push(5,1);
    s.push(6,1);
    s.push(7,1);
    s.push(8,1);
    s.push(100,2);
    s.push(200,2);
    s.pop(1);
    s.pop(1);
    s.pop(1);
    s.pop(2);
    s.pop(2);
    s.push(1000,1);
    s.push(4545,2);
    s.push(490,2);
    s.push(3000,1);
    s.push(400000,2);
    s.push(1343,1);
    s.display();
    // output : 1 2 3 4 5 1000 3000 400000 490 4545 

    
}
