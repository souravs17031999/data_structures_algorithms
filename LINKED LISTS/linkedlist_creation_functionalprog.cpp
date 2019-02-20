// program for linked list creation using only functions 
// @author sourav kumar , 20-02-2019
#include <iostream>
using namespace std; 
struct node{  
    int data;
    node *next;
};
// passing pointer to pointer as we are not passing the head , instead we are passing address of head pointer which stores the address of where head is 
void insert(node **head, int n){
node *new_node = new node;
new_node->data = n;
new_node->next = NULL;
    if(head == NULL){
       *head = new_node;
        return;
    }
new_node->next = *head;  // now we can't use simply head , becuase we donot want address of head pointer but we want the address which head pointer has stored 
*head = new_node;
}
// passing address of head pointer 		
void display(node **head){
    node *ptr = *head; // assinging address which  head pointer stored to ptr pointer 
    if(head == NULL){
        cout << "empty" << endl;
        return;
        
    }
    while(ptr != NULL){
        cout << ptr->data << " ";
        ptr = ptr->next;
        }
}

int main(void){
	  // initializing head pointer to NULL 
      node *head = NULL;
	  insert(&head,1);  // we have to pass address of head pointer 
	  insert(&head,2);
	  display(&head);
}