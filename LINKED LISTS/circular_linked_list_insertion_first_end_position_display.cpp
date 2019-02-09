// program to insert nodes at beginning , at end and in middle of circular linked lists and then display it 
// @author sourav kumar , 01-02-2019
#include <iostream>
using namespace std;
struct node{
	int data;
	node *next;
};
class linked_list{
	private:
	node *head;
	public:
	linked_list(){
		head = NULL;
	}
	// fucntion to insert nodes in beginning of circular linked lists 
	void cir_insert_beg(int n){
		node *new_node = new node;
		new_node->data = n;
		new_node->next = NULL;
		if(head == NULL){
			head = new_node;
			new_node->next = head;
			cout << n << " inserted as head " << endl;
			return;
		}
		node *ptr = head;
		while(ptr->next != head){
			ptr = ptr->next;
		}
		ptr->next = new_node;
		new_node->next = head;
		cout << n << " inserted at end " << endl;
		
	}
	// function to insert nodes at last of circular linked lists 
	void cir_insert_last(int n){
		node *new_node = new node;
		new_node->data = n;
		new_node->next = NULL;
		node *ptr = head;
		while(ptr->next != head){
			ptr = ptr->next;
		}
		ptr->next = new_node;
		new_node->next = head;
		cout << n << " inserted at end " << endl;
		
	}
	// function to insert nodes after some given element in circular fashion
	void cir_insert_at(int p,int n){
		node *new_node = new node;
		new_node->data = n;
		new_node->next = NULL;
		node *ptr = head;
		node *temp;
		while(ptr->next != head){
			if(ptr->data == p){
				temp = ptr->next;
				break;
			}
			ptr = ptr->next;
		}
		ptr->next = new_node;
		new_node->next = temp;
		cout << n <<" inserted at position after element " << p <<endl; 
		
	}
	
	// function to display the circular linked lists 
	void display(){
		if(head == NULL){
			cout << "empty list " << endl;
		}
		node *ptr = head;
		do{
			cout << ptr->data << " ";
			ptr = ptr->next;
		}
		while(ptr != head);
		cout << ptr->data;
		
	}
};

int main(){
	linked_list a;
	a.cir_insert_beg(10);
	a.cir_insert_beg(20);
	a.cir_insert_beg(30);
	a.cir_insert_beg(40);
	a.cir_insert_beg(50);
	a.display();
}
