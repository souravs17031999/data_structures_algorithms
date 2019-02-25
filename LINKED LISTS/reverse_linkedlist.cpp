// program for reversal of linked list 
// @author sourav kumar , 25-02-2019
#include <iostream>
using namespace std;
// class for creating structure of node 
class node{
    public:
        int data;
        node *next;
};
// class linked list for implementing functions of linked list 
class linked_list{
    node *head;
    public:
        linked_list(){
            head = NULL;
        }
		// function for inserting element at the last of linked list 
        void insert(int n){
            node *new_node = new node;
            new_node->data = n;
            new_node->next = NULL;
            if(head == NULL){
                head = new_node;
                return;
            }
            node *ptr = head;
            while(ptr->next != NULL){
                ptr = ptr->next;
            }
            ptr->next = new_node;
            
        }
		//function for dispalying the linked list 
        void display(){
            node *ptr = head;
            if(head == NULL){
                cout << "empty list" << endl;
                return;
            }
            while(ptr != NULL){
                cout << ptr->data << "->";
                ptr = ptr->next;
            }
            cout << "NULL" << endl;
        }
		// program for reversing the linked list 
        void reverse(){
			// initialising three pointers cur as head and other two as NULL
            node *cur = head;
            node *prev = NULL;
            node *ptr = NULL;
			// transverse till the current node becomes null which happens after it goes after the last node 
            while(cur != NULL){
                ptr = cur->next;  // incrementing the ptr because after reversing we will lose the linked list  
                cur->next = prev;  // reversing the link 
                prev = cur;   // incrementing prev 
                cur = ptr;    // incremneting cur 
            }
            head = prev;    // finally pointing head to prev pointer which will be at last node 
        }
};
// main driver function for testing out other functions 
int main(void){
    linked_list l;
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.insert(5);
    l.display();  // 1->2->3->4->5->NULL
    l.reverse();
    l.display();  // 5->4->3->2->1->NULL
}
