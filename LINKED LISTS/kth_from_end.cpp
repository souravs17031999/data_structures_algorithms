//Program for given a linked list, find out kth node from end 
//@author sourav kumar , 17-03-2019
// solution - 0(N) where N is length of list (no of nodes)
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
		/* logic is to keep two pointers and one of them moved to kth node from head, and after that move both one by one , one of which when reaches last node , 
			the other one reaches kth from end */
		int k_node_end(node *&head, int k){
		    if(head == NULL){
		        return -1;
		    }
		    node *ptr1 = head;
		    node *ptr2 = head;
		    while(k--){
		        ptr2 = ptr2->next;
		    }
		    while(ptr2 != NULL){
		        ptr2 = ptr2->next;
		        ptr1 = ptr1->next;
		    }
		    return ptr1->data;
		}
};
//driver main function to test other functions
int main(){
    linked_list l;
    node *head = NULL;
    l.insertion(head, 1);
    l.insertion(head, 2);
    l.insertion(head, 3);
    l.insertion(head, 4);
    l.insertion(head, 5);
    l.insertion(head, 6);
    l.insertion(head, 7);
    l.insertion(head, 8);
    l.insertion(head, 9);
    l.insertion(head, 10);
    l.display(head);
    int n = 8;
    cout << n << " th node from the end of list is " << l.k_node_end(head, n);
}
// another solution with same time complexity - 0(N) where N is length of list (no of nodes)
/* int length(node *&head){
		    if(head == NULL){
		        return 0;
		    }
		    int count = 0;
		    node *ptr = head;
		    while(ptr != NULL){
		        ptr = ptr->next;
		        count = count + 1;
		    }
		    return count;
		}	
		void k_node_end(node *&head, int k){
		    int n = length(head) - k;
		    node *ptr = head;
		    for(int i = 1; i <= n-1; i++){
		        ptr = ptr->next;
		    }
		    cout << ptr->data;
		} */