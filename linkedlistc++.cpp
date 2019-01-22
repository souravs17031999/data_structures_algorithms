// @author sourav kumar , 20-01-2019

//program for creating a linked list and displaying it,  time complexity is 0(1) for inserting at beginning 

#include <iostream>
using namespace std;
struct node{   // using structure because we just don't need a unit of block but a block of two units which contains data and address.
    int data;
    node *next;
};
class linked_list{
    private:
        node *head;  // creating a head node pointer for keeping track of head node  
    public:
        linked_list(){ 
        head  = NULL; // calling the constructor once will initialize the empty list and head pointing towards nothing (null)
    }   
		// function to create  a new node
        void add_node(int n){
			node *temp  = new node; // creating  a new node temp
			temp->data = n;  // entering the data unit of new node created
			temp->next = head; // entering the address of temp same as last head address so that new node is linked to next node from the beginning
			head = temp;  //assigning head to the new node created by pointing head towards the same node as temp 
        }
		// function to display and print the linked list
	void display(){
			node *ptr;  // creating a temp pointer variable ptr
			ptr = head; // assigning head to ptr
			while(ptr != NULL){  // checking if the ptr reaches the last node
				cout << ptr->data << " ";  // pritning the contents of nodes
				ptr = ptr->next;  // assigning ptr address of next node
			}
    }
};
// driver function for showcasing the program for linked list
int main(void){
    int n = 5;
    linked_list a;  // creation of a new object and calling constructor (auto)
    for(int i = 0; i <= n-1; i++){
        a.add_node(i); //calling add_node fucntion
    }
    
    a.display(); //calling display fucntion 
}
