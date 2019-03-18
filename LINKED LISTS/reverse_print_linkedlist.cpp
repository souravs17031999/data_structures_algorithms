// program to reverse print the entire linked list without actually reversing it
// logic is to use stack and push one by one node , then printing out and pop each time simultaneously
// @author sourav kumar , 18-03-2019
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
		    cout << "printing original list: ";
			if(head == NULL){
				cout << "empty list" << endl;
				return;
			}
			node *ptr = head;
			while(ptr != NULL){
				cout << ptr->data  << " ";
				ptr = ptr->next;
			}
			cout << endl;
			}
		// using stack to reverse print the linked list without actually reversing it 	
		void reverse_print(node *&head){
		    cout << "printing reversed list: ";
		    node *ptr = head;
			// using stl container stack 
		    stack <int> s;
		    while(ptr != NULL){
		        s.push(ptr->data);  // pushing entire list to stack 
		        ptr = ptr->next;
		    }
			// printing the top every time and then pop the top element 
		    while(!s.empty()){
		        cout << s.top() << " ";
		        s.pop();
		    }
		    
		}	
};
// main driver function to test other functions 
int main(){
    node *head = NULL;
    linked_list l;
    for(int i = 1; i <= 5; i++){
        l.insertion(head, i);
    }
    l.display(head);
    l.reverse_print(head);
}