#include <iostream>
using namespace std;
// structure for node 
class node{
    public:
        int data;
        node *next;
        node(int x){
            this->data = x;
            this->next = NULL;
        }
};
// structure for including all the functions for linked _list
class linked_list{
    public:
		// insertion of node in a linked list 
		void insertion(node *&head, int n){
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
};			
int main(void){
    return 0;
}
