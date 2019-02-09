// program for Insertion and deletion of nodes in doubly linked lists
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
	    new_node->prev = NULL;
	    new_node->next = NULL;
	    node *ptr = head;
	    while(ptr != NULL){
	        if(ptr->data == p){
	            break;
	        }
	        ptr = ptr->next;  
	    }
	    new_node->next = ptr->next;
	    ptr->next = new_node;
	    new_node->prev = ptr;
	    if(new_node->next != NULL){
	        new_node->next->prev = new_node;
	    }
	    
	}
	void insert_last(int n){
	    node *new_node = new node;
	    new_node->data = n;
	    new_node->next = NULL;
	    if(head == NULL){
	        new_node->prev = NULL;
	        head  = new_node;
	        return;
	    }
	    node *ptr = head;
	    while(ptr->next != NULL){
	        ptr = ptr->next;
	    }
	    ptr->next = new_node;
	    new_node->prev = ptr;
	}
	void delete_at(int n){
	    if(head == NULL){
	        cout << "empty list , underflow" << endl;
	        return;
	    }
	    node *ptr = head;
        node *temp;
        while(ptr != NULL){
            if(ptr->next->data == n){
                temp = ptr->next->next;
                break;
          }
            ptr = ptr->next;
      }
      
      delete ptr->next;
      ptr->next = temp;
      temp->prev = ptr;
      
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
	a.insert_at(25,28);
	a.insert_last(40);
	a.delete_at(25);
	a.display();
}
