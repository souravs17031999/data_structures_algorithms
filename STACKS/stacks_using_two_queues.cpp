// program for implementing stacks using two queues 
/*logic is to simply maintain a active queue and a inactive queue , where active queue contains pushed element for enqueue and in deque , it pops up and copies all to
inactive one till only one element is left and last left one is returned and then queues names are reversed so that now inactive one becomes active and active becomes 
inactive one */
// @author sourav kumar , 22-03-2019
// push : 0(1)
// POP : THETA(N)
#include <iostream>
using namespace std;
// class to represent the node structure
class node{
    public:
    int data;
    node *next;
};
// class to implement queues using linked list 
class queue{
  private:
  
  node *front;
  node *rear;
  public:
  queue(){
      front = NULL;
      rear = NULL;
  }
  int size = 1;
  // fucntion to push elements at the end of queue 
  void enqueue(int n){
      node *new_node = new node;
      new_node->data = n;
      new_node->next = NULL;
      if(front == NULL && rear == NULL){
          front = rear = new_node;   
          return;
      }
	  rear->next = new_node;
      rear = new_node;
      size++;
  }
  // function to implement popping from the queue
  int dequeue(){
     if(front == NULL && rear == NULL){
         return -1;
     }
     if(front == rear){
	 int p = front->data;
         front = rear = NULL;
         return p;
     }
     node *ptr = front;
     front = front->next;
     int temp = ptr->data;      
     delete ptr;
     size--;
     return temp;
  }
  bool isempty(){
      if(front == NULL && rear == NULL){
          return 1;
      }
      return 0;
  }
  int sizes(){
      return size;
  }
  void display(){
      if(front == NULL && rear == NULL){
          return;
      }
      node *ptr = front;
      while(ptr != NULL){
          cout << ptr->data << " ";
          ptr = ptr->next;
      }
      cout << endl;
  }
};
// implementing functions of stack 
class stack{
    public:
        queue q1;
        queue q2;
		// pushing directly to active queue  
        void push(int n){
            q1.enqueue(n);
            }
		// copying elements from active to inactive and then popping last one from active  
        int pop(){
            if(q1.isempty()){
                return -1;
            }
			//copy in inactive one till only one element is left in active one and then return that left one 
            while(q1.sizes() != 1){
                q2.enqueue(q1.dequeue());
            }
            int temp = q1.dequeue();
            // now names are reversed so that we do not have to copy back the elements and the same process can now go on with reversed names 
			queue q = q1; 
            q1 = q2; 
            q2 = q;
            return temp;
        }
};
int main(){
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
	// 3 2 1
}