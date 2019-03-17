// program for creating two new linked lists of which nodes are to be sum of odd and even postitions respectively taken from a already created singly linked list
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
				cout << ptr->data << " ";
				ptr = ptr->next;
			}
			cout << endl;
			}
		// function for creation of two new linked lists as stated in the problem above	
		void com_linked_list(node *&head1){
			node *ptr1 = head1;   // making the ptr1 to point to head of given (already , created linked list)			
			node *ptr2 = head1->next;   // making the ptr2 to point to next of head of given (already , created linked list)
			node *head2 = NULL;          
			node *head3 = NULL;
			int temp1, temp2;    // to save the value of current node at each iteration
			while(ptr1->next->next != NULL && ptr2->next != NULL){     //ptr1 should be stopped just before one node from last , ptr2 should be at last node 
				temp1 = ptr1->data;     // saving earlier ptr1 value
				temp2 = ptr2->data;     // saving earlier ptr2 value
				ptr1 = ptr1->next->next;  // now incrementing ptr1 by two so that it points to next odd postioned node 
				ptr2 = ptr2->next->next;   // now incrementing ptr2 by two so that it points to next even postioned node
				insertion(head2, temp1 + ptr1->data);   // inserting to linked list 2
				insertion(head3, temp2 + ptr2->data);   // inserting to linked list 3
			}
			// display the odd sum positioned linked list
			display(head2);
			// display the even sum positioned linked list
			display(head3);
			}
};    
int main(void){
    linked_list l;
    node *head1 = NULL;
	// creating a already linked list originally
    l.insertion(head1, 1);
    l.insertion(head1, 2);
    l.insertion(head1, 3);
    l.insertion(head1, 4);
    l.insertion(head1, 5);
    l.insertion(head1, 6);
    l.insertion(head1, 7);
    l.insertion(head1, 8);
    l.insertion(head1, 9);
    l.insertion(head1, 10);
	// display the original linked list 
    l.display(head1);
	// for creation of new linked lists 
    l.com_linked_list(head1);
    /*
	final output : 1 2 3 4 5 6 7 8 9 10 
	4 8 12 16 
	6 10 14 18 
	*/
}
