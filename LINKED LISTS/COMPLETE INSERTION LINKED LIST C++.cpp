//@author sourav kumar , 18-01-2019

// program for linked list insertion
#include <iostream>
using namespace std; 
struct node{  // determining a structure of two units for each node
    int data;
    node *next;
};
class linked_list{  // making a class for different fucntions 
    private:
        node *head;  // creating a pointer for a reference to start of node
    public:
        linked_list(){
        head  = NULL;  // creating a empty linked list with a head node pointing towards nothing 
    }
		//function to create and insert the nodes at nth position
        void add_node(int data, int n){
            node *new_node = new node;  // creation of new node
            new_node->data = data;  // assigning value to new node
            new_node->next = NULL; // assigning new node pointer towards nothing
            if(n == 1){    // insertion of node at the beginning n=1 
                new_node->next = head;  // assigning head address to new_node address 
                head = new_node; // making new_node as head 
                return;          // returning as no need to do anything further
            }
            node *ptr;  //run if position is other than beginning 
            ptr = head;  // making a temp var so as not to lose the reference head
            for(int i = 0; i <= n-3; i++){  // run the loop n-3 times so to keep the ptr till n-1 position 
                ptr = ptr->next;  // assigning the next address to ptr
            }
            new_node->next = ptr->next;  // linking the new_node to next node 
            ptr->next = new_node;  // linking the n-1th node to new_node
        }
	// function to display the linked list	
    void display(){
        node *ptr;
        ptr = head; 
        while(ptr != NULL){
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }
};
int main(void){
    int data,n;
    linked_list a;
    a.add_node(1,1);
    a.add_node(2,2);
    a.add_node(3,1);
    a.add_node(5,3);
    a.display();
	// output : 3 1 5 2
}
