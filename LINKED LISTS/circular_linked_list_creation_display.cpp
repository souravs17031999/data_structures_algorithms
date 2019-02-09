// program to create circular linked lists and then display it 
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
	// fucntion to insert nodes into circular linked list 
	void cir_insert(int n){
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
	// function to display circular linked list 
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
	a.cir_insert(10);
	a.cir_insert(20);
	a.cir_insert(30);
	a.cir_insert(40);
	a.cir_insert(50);	
	a.display();
}
