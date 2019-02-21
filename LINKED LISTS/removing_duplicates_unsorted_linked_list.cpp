// program for removing duplicates from unsorted linked lists 
// @author sourav kumar , 21-02-2019 
/* this problem can be more efficiently done by firstly sorting it and then applying the same logic as was done in sorted linked list but this will not preserve 
the order of the original list so, this would go for 0(n^2) where n is the length of the list otherwise hashing could also be applied for 0(n) . */
#include <iostream>
using namespace std;
//creating  a structure for linked lists node
class node{
    public:
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
            return;
        }
        node *ptr;  // now this will only run when the linked list is not empty and there is at least  a element present so we insert it after the last element
        ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next;
            }
        ptr->next = new_node;    
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
        
    }
    // fucntion to remove duplicates
    void dup_unsort(){
        node *ptr = head;  // keeping a reference to head as ptr for transversing outer loop
        node *cur;   // creating current ptr for transversing inner loop
        while(ptr != NULL){  
            cur = ptr;   // start with both pointing to same element 
            while(cur->next != NULL){   // we have to stop just one node before the last one as we are checking for cur->next->data in the next if condition , if done otherwise then there will be runtime fault
                if(ptr->data == cur->next->data){   // checking if the data at the outer loop ptr is same as current ka next pointer ka data
                    node *temp = cur->next;   // storing the address of the node to be deleted 
                    cur->next = cur->next->next;  // linking the current pointer to the node after the deleted node 
                    delete temp;   // destroying the duplicate node 
                    
                }
                else{   // only increment when there is no match otherwise we will skip the current element to be matched with newly formed link with the node element
                cur = cur->next;}
            }
            ptr = ptr->next;   // normal increment the outer ptr pointer till the last node 
        }
        
    }
    
};
// driver function to test all the other functions 
int main(void){
    linked_list l;
    l.insert(10);
    l.insert(12);
    l.insert(11);
    l.insert(11);
    l.insert(12);
    l.insert(11);
    l.insert(10);
    l.display();  // 12 12 12 21 41 43 21 21 
    l.dup_unsort();  
    l.display();  // 12 21 41 43 
}