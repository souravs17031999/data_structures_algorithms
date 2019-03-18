// program for floyd cycle detection algorithm to detect a loop in linked list 
// logic is to set two pointers fast and slow and whenever a list contains loop then fast and slow pointers will meet at one time (collision of both pointers).
// @author sourav kumar, 18-03-2019
#include <iostream>
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
		// detect the loop 	
		void detect_loop(node *&head){
			// setting two pointers fast and slow , fast moving two nodes and slow moving one node 
		    node *fast = head->next;
		    node *slow = head;
			// transversing whole linked list 
		    while(fast != NULL && slow != NULL){
				// when fast and slow are pointing to the same address 
		        if(fast == slow){
		            cout << "loop detected" << endl;
		            return;
		        }
				// incrementing two pointers 
		        fast = fast->next->next;
		        slow = slow->next;
		    }
		    cout << "no loop" << endl;
		}	
};
// driver main function to test other functions 
int main(){
    linked_list l;
    node *head = NULL;
    for(int i = 1; i <= 5; i++){
        l.insertion(head, i);
    }
    // head->next->next->next->next->next = head->next; output : loop detected 
    // otherwise no loop 
    l.detect_loop(head);
}