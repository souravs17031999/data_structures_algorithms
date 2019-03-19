// program for reversing the list using stacks 
// logic is push all the nodes one by one while transversing the list , and then pop out and link each node one by one thereby reversing the list using new nodes 
#include <bits/stdc++.h>
using namespace std;
// structure for node 
class node{
    public:
        int data;
        node *next;
};  
// structure for including all the functions for linked _list
class linked_list{
    public:
		// insertion of node in a linked list 
		void insertion(node *&head, int n){
			if(head == NULL){
				node *new_node = new node;
				new_node->data = n;
				new_node->next = NULL;
				head = new_node;
				return;
			}
			node *ptr = head;
			while(ptr->next != NULL){
				ptr = ptr->next;
				}
			node *new_node = new node;
			new_node->data = n;
			new_node->next = NULL;
			ptr->next = new_node;
			}
		// printing the entire linked list 	
		void display(node *&head){
			if(head == NULL){
				cout << "empty list" << endl;
				return;
			}
			node *ptr = head;
			while(ptr != NULL){
				cout << ptr->data << "->";
				ptr = ptr->next;
			}
			cout << "NULL" << endl;
			}
		// function for reversing the linked list 	
		void reverse_list(node *&head){
		    if(head == NULL){
		        return;
		    }
			// using stl function stack for implementing functions of stack 
		    stack <node *> s;
		    node *ptr = head;
		    while(ptr->next != NULL){
		        s.push(ptr);    // passing entire structure (node) to stack 
		        ptr = ptr->next;
		    }
			// now making last one node as head 
		    head = ptr;
		    while(!s.empty()){
		        ptr->next = s.top();   // linking the current node to already made node of stack 
		        ptr = ptr->next;       
		        s.pop();               // deleting the elements in stack 
		    }
		    ptr->next = NULL;          //finally making the last one as pointing to NULL 
		}	
};
int main(){
    linked_list l;
    node *head = NULL;
    for(int i = 1; i <= 5; i++){
        l.insertion(head, i);
    } 
	l.display(head);   // 1->2->3->4->5->NULL
    l.reverse_list(head);
    l.display(head);   // 5->4->3->2->1->NULL

}