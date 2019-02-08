// program for creation of doubly linked list and transversal in forward and backward  
// @author sourav kumar , 08-02-2019
#include<iostream>
using namespace std;
struct node{
	int data;
	node *next;
	node *prev;
	
};

class linked_list{
	private:
		node *head;
	public:
		linked_list(){
			head = NULL;
		}	
	void insert_beg(int n){
		node *new_node  = new node;
		new_node-> data = n;
		new_node->prev = NULL;
		new_node->next = NULL;
		if(head == NULL){
			head = new_node;
			return;
		}
		head->prev = new_node;
		new_node->next = head;
		head = new_node;
	}
	void display(){
	    node *ptr = head;
	    node *temp;
		cout << "tranversing doubly linked list in forward direction" << endl;
	    while(ptr != NULL){
	        cout << ptr->data << " ";
	        temp = ptr;
	        ptr = ptr->next;  
	    }
	    cout << "transversing doubly linked list in reverse direction" << endl;
	    while(temp != NULL){
	        cout << temp->data << " ";
	        temp = temp->prev;
	    }
	    
	}
	
};
int main(){
	linked_list a;
	a.insert_beg(35);
	a.insert_beg(30);
	a.insert_beg(25);
	a.insert_beg(20);
	a.insert_beg(10);
	a.insert_beg(5);
	a.display();
}
