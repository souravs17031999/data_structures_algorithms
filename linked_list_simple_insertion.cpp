// program for all functions of linked list , assuming the first index to be 1 , functions include insertion , deletion , display (this is modification of insertion function rest are same)
// @author sourav kumar , 25-01-2019 

#include <iostream>
using namespace std;
//creating  a structure for linked lists node
struct node{
    int data;
    node *next;
};
//defining a class for all functions for linked list
class linked_list{
    private:
        node *head;    // declaring head node 
    public:
        linked_list(){
            head = NULL;  // initializing head node with null
        }
	// fucntion to insert into a linked list without any position 	
    void insert(int num){
        node *new_node = new node;  //creating the node to be inserted and then inserting the data and pointing towards null
        new_node->data = num;
        new_node->next = NULL;
        if(head == NULL){    // checking whether the node to be inserted is at position 1 (at the beginning)
            new_node->next = head;  // making the new_node to be at the beginning by assigning the next node address (which earlier head stored)
            head = new_node;  // making the new_node,  the head node
            cout << num << " inserted at beginning" << endl;;
            return;
        }
        node *ptr;  // now this will only run when the linked list is not empty and there is at least  a element present so we insert it after the last element
        ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next;
            }
        ptr->next = new_node;    
    }
	// fucntion to delete the node at nth position
    void deletion(int n){
        if(head == NULL){  // checking whether the list doesn't contain anything then return empty list with a string (kind of exception handler at runtime)
            cout << "not possible to delete , empty list" << endl;
            return;
        }
        if(n == 1){    // deleting the first node 
            node *ptr;
            ptr = head;
            head = ptr->next;  // creating the link between the second node and head and thus destroying the link between head and first node 
            delete ptr;  // killing the first node and freeing the memory
            cout << "first node deleted" << endl;
            return;
            
        }
		// run when any position other than beginning 
        node *ptr1;  
        for(int i = 0; i <= n-3; i++){
            ptr1 = ptr1->next;  // stooping at n-1th position 
        }
        node *ptr2;
        ptr2 = ptr1->next; // storing the address of the node to be killed (deleted)
        ptr1->next = ptr2->next;  // creating the link between n-1th and n+1th node 
        delete ptr2;  // killing the nth node and freeing the memory 
        cout << "node deleted at position " << n << endl;
        
    }
	// function to display the entire linked list 
    void display(){
        node *ptr;
        ptr = head;
        int count = 0;
        if(ptr == NULL){ // show the warning if empty linked list is said to be displayed
            cout << "empty list" << endl; 
			return;
        }
        while(ptr != NULL){  // transverse the entire linked list and print the data and also increment the ptr to point to next node 
            cout << ptr->data <<" ";
            count++;
            ptr = ptr->next;
        }
        cout << endl;
        cout << "linked list contains " << count << " elements" << endl;
    }
    
};
// driver function to test all the other functions 
int main(void){
    // call any function to test it :) 
    linked_list a;
    a.insert(10);
    a.insert(20);
    a.insert(30);
    a.display();
    
}