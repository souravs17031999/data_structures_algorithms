// program for implementing priority queue using singly linked list 
// @author sourav kumar , 23-02-2019
#include <iostream>
using namespace std;
class node{
    public:
        int data;
        int priority;
        node *next;
};        
// class for implementing functions of priority_queue
class queue{
    node *head;
    public:
        queue(){
            head = NULL;
        }
		// function for pushing element into queue according to their priority 
        void push(int n, int p){
			// firstly creating a new node and putting data and priority 
            node *new_node = new node;
            new_node->data = n;
            new_node->priority = p;
            new_node->next = NULL;
			// now first node is always be the first irrespective of its priority 
            if(head == NULL){
                head = new_node;
                return;
            }
			// if the new node priority is more than the first node priority then we have to insert it at the first place and change the head to new node  
            if(head->priority > p){
                new_node->next = head;
                head = new_node;
                return;
            }
			/* else a ptr should point to the node just before the node which has lesser priority than the incoming node and insert it there or if it has the least priority 
			then it should be able to insert it as the last node*/
            node *ptr = head;
            while(ptr->next != NULL){
                if(ptr->next->priority > p){
                    break;
                }
                ptr = ptr->next;
            }
            new_node->next = ptr->next;
            ptr->next = new_node;
            
        }
		// returning (dequeueing) the highest priority element from the queue , always the first node will be the highest priority element 
        int pop(){
            if(head == NULL){
                cout << "underflow" << endl;
                return 0;
            }
            node *temp = head;
            int r = temp->data;
            head = head->next;
            delete temp;
            return r;
        }
		// displaying the entire priority_queue
        void display(){
          node *ptr = head;
          while(ptr != NULL){
              cout << ptr->data << " ";
              ptr = ptr->next;
              
          }
          cout << endl;
          
        }
		// returning the first element in the priority_queue 
        int peek(){
            return head->data;
        }
};
// driver main function for testing out other functions 
int main(void){
    queue q;
    q.push(4,1);
    q.push(5,2);
    q.push(6,3);
    q.push(7,0);
    q.display();  // 7 4 5 6
    
}
