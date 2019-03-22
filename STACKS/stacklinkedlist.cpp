// program to create stack using linked list 
// @author sourav kumar , 09-02-2019
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
      top = NULL; // making top as NULL intially
  }
  // fucntion to push data on stack 
  void push_stack(int n){
      node *temp = new node;  // creating a temp node for pushing node value 'n' to stack 
      if(!temp){  // checking for stack overflow 
          cout << "stack overflow" << endl;
          return;
      }
      temp->data = n;  // pushing data into temp node created 
      temp->link = NULL;  // making temp link as NULL 
      if(top == NULL){   // checking for first stack block to be pushed 
          top = temp;
          return;
      }
	// runs when it is not the first stack 
      temp->link = top;
      top = temp;
  }
  // fucntion to pop data from the stack 
  void pop_stack(){
      if(top == NULL){   // checking for stack underflow 
          cout << "stack underflow" << endl;
          return;
      }
      node *temp = top;  // creating the link from top to node just after the first node , so that now top points to second node (node after the node which is popped out)
      top = temp->link;
      delete temp;  // destroying the first node from stack 
  }
  int tops(){
      if(top == NULL){
          return -1;
      }
      return top->data;
  }
   bool isempty(){
      if(top == NULL){
          return 1;
      }
      return 0;
  }
  // fucntion to display all the elements of the stack 
  void display(){
      if(top == NULL){   // checking for empty stack as in that case top points to NULL 
          cout << "empty stack" << endl;
          return;
      }
      node *temp = top;
      while(temp != NULL){  // transversing till the last node as last node link is NULL 
          cout << temp->data << " "; 
          temp = temp->link;   // incrementing the top pointer so that everytime it points to next node when current link is not NULL 
      }
  }
};
// driver fucntion to test above fucntions 
int main(void){
    stack a;   // creating a object for class stack 
    a.push_stack(2);   // pushing elements to stack 
    a.push_stack(4);
    a.push_stack(6);
    a.push_stack(8);
    a.push_stack(10);
    a.pop_stack();  // popping elements from stack 
    a.display();   // display the whole stack 
    
}
