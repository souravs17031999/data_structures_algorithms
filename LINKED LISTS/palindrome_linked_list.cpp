// program for implementing to check if singly linked list is palindrome or not 
/* logic is to keep a stack of visited nodes and then pop out one by one and then again keep transversing it from start so if anyone node doesn't matches the popped
character then , not palindrome otherwise palindrome. */
// @author sourav kumar , 01-04-2019
#include <bits/stdc++.h>
using namespace std;
// structure for node 
class node{
    public:
        char data;
        node *next;
        node(char x){
            this->data = x;
            this->next = NULL;
        }
};
// structure for including all the functions for linked _list
class linked_list{
    public:
		// insertion of node in a linked list 
		void insertion(node *&head, char n){
			node *new_node = new node(n);
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
		// checking for palindrome 	
		string palindrome(node *&head){
		    if(head == NULL){
		        return "EMPTYLIST";
		    }
			// using stl for stack 
		    stack <char> s;
		    node *ptr = head;
		    while(ptr != NULL){
		        s.push(ptr->data);
		        ptr = ptr->next;
		    }
		    node *ptr1 = head;
		    int flag = 0;
		    while(!s.empty() && ptr1->next != NULL){
		        if(ptr1->data != s.top()){
		            return "NO";
		        }
		        s.pop();
		        ptr1 = ptr1->next;
		    }
		    return "YES";
		}	
};			
int main(void){
    linked_list l;
    node *head = NULL;
    l.insertion(head, 'R');
    l.insertion(head, 'A');
    l.insertion(head, 'D');
    l.insertion(head, 'A');
    l.insertion(head, 'R');
    l.display(head);
    cout << l.palindrome(head); // YES
    return 0;
}