// program for all functions of queue implementing through linked lists 
// @author sourav kumar , 18-02-2019
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
  /* in this we need to declare two pointers due to constraint that both enqueue and dequeue should be done in 0(1) otherwise one of the operation will take 0(n)
  in worst case , now front will point to head of queue and rear will point to the last node of the queue in the coming functions */
  node *front;
  node *rear;
  public:
  queue(){
      front = NULL;
      rear = NULL;
  }
  // fucntion to push elements at the end of queue 
  void enqueue(int n){
      node *new_node = new node;
      new_node->data = n;
      new_node->next = NULL;
      if(front == NULL && rear == NULL){
          front = rear = new_node;  // pointing front and rear to the same very first node 
          return;
      }
	  // now since incoming node is after the first node so we have to increment the rear node by pointing to the current node 
      rear->next = new_node;
      rear = new_node;
  }
  // function to implement popping from the queue
  int dequeue(){
	  // if the queue is already empty 
     if(front == NULL && rear == NULL){
         cout << "queue underflow" << endl;
         return -1;
     }
	 // if the deleted node is the very last and only node in the queue 
     if(front == rear){
         front = rear = NULL;
         return 0;
     }
	 // otherwise simply increment the front pointer by pointing to the next node (after the node to be dequeued)
     node *ptr = front;
     front = front->next;
     int temp = ptr->data; // keeping the data of the destroyed node to be returned 
     delete ptr;  // destroying the node to be deleted from memory
     return temp;
  }
  void display(){
	  // check if the queue is already empty 
      if(front == NULL && rear == NULL){
          cout << "empty queue" << endl;
          return;
      }
	  // otherwise transverse the whole queue
      node *ptr = front;
      cout << "Queue: ";
      while(ptr != NULL){
          cout << ptr->data << " ";
          ptr = ptr->next;
      }
      cout << endl;
  }
  // check if the queue is empty and return true otherwise false 
  string isempty(){
      if(front == NULL && rear == NULL){
          return "TRUE";
      }
      else{
          return "FALSE";
      }
  }
};
// main driver fucntion to test other functions 
int main(void){
    queue q;
    for(int i = 1; i <= 5; i++){
        q.enqueue(i);
    }
    q.display();  // Queue: 1 2 3 4 5
    q.dequeue();  //  2 3 4 5
    q.dequeue();  //   3 4 5
    q.display(); // Queue: 3 4 5
    q.dequeue(); // 4 5
    q.dequeue(); // 5
    q.display();// Queue: 5
    q.dequeue(); // empty queue 
    q.display(); // empty queue
    q.dequeue(); // queue underflow
    q.display(); // empty queue 
    cout << q.isempty(); // TRUE
}
