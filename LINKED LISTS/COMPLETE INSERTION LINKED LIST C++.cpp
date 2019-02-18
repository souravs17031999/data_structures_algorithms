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
        void add_node(int n){
        node *new_node = new node;
        new_node->data = n;
        new_node->next = NULL;
        if(head == NULL){
           head = new_node;
            return;
    }
        node *ptr = head;
        new_node->next = head;
        head = new_node;
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
