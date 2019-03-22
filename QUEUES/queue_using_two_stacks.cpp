// program for implementing queues through two stacks 
/* logic is to maintain two stacks one of which (s1) is used for simply pushing when enqueue is called and then when dequeue is called, then we copy the elements from 
stack 1 to stack 2 (s2) and then pop the top element from stack 2 which is the required one.
also , it can be seen that order is reversed as in stack when we copy from stack 1 to stack 2 but overall order is same as required for queue operations.
enqueue : 0(1) 
dequeue : theta(n)
*/
#include <iostream>
using namespace std;
// structure for every node in the stack 
struct node{
    int data;
    node *link;
};
// class to implement stack 
class stack{
  private:
  node *top;
  public:
  stack(){
      top = NULL; 
  }
  // fucntion to push data on stack 
  void push(int n){
      node *temp = new node;  
      if(!temp){   
          return;
      }
      temp->data = n;   
      temp->link = NULL;   
      if(top == NULL){    
          top = temp;
          return;
      }
	 
      temp->link = top;
      top = temp;
  }
  // fucntion to pop data from the stack 
  void pop(){
      if(top == NULL){    
          return;
      }
      node *temp = top;  
      top = temp->link;
      delete temp;   
  }
  bool isempty(){
      if(top == NULL){
          return 1;
      }
      return 0;
  }
  int tops(){
      if(top == NULL){
          return -1;
      }
      return top->data;
  }
  // fucntion to display all the elements of the stack 
  void display(){
      if(top == NULL){    
          cout << "empty" << endl;
          return;
      }
      node *temp = top;
      while(temp != NULL){   
          cout << temp->data << " "; 
          temp = temp->link;    
      }
      cout << endl;
  }
  
};
class queue{
  public:
    stack s1;
    stack s2;
    void enqueue(int n){
        s1.push(n);
    }
    int deque(){
        if(s1.isempty() && s2.isempty()){
            cout << "error , underflow" << endl;
            return -1;
        }
        if(s2.isempty()){
            while(!s1.isempty()){
                s2.push(s1.tops());
                s1.pop();
            }
        }
        int x = s2.tops();
        s2.pop();
        return x;
    }
    void display(){
        s1.display();
        s2.display();
    }
};
int main(){
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << q.deque() << endl;
    cout << q.deque() << endl;
    q.enqueue(10);
    q.enqueue(20);
    cout << q.deque() << endl;
    cout << q.deque() << endl;
}