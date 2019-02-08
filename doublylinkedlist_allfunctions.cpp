// program for transversal in forward and backward and insertion at beg 
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
	    while(ptr != NULL){
	        cout << ptr->data << " ";
	        temp = ptr;
	        ptr = ptr->next;  
	    }
	    cout << endl;
	    while(temp != NULL){
	        cout << temp->data << " ";
	        temp = temp->prev;
	    }
	    
	}
	void insert_at(int p , int n){
	    node *new_node = new node;
	    new_node->data = n;
	    node *ptr;
	    while(ptr != NULL && ptr->data == p){
	        ptr = ptr->next;  
	    }
	    new_node->next = ptr->next;
	    ptr->next = new_node;
	    new_node->prev = ptr;
	    if(new_node->next != NULL){
	        new_node->next->prev = new_node;
	    }
	    
	}
	
};
int main(){
	linked_list a;
	a.insert_beg(2);
	a.insert_beg(4);
	a.insert_beg(6);
	a.insert_at(4,9);
	a.display();
}
