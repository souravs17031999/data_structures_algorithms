// program for displaying union of two linked lists 
// @author sourav kumar , 21-03-2019
#include <iostream>
using namespace std;
// structure for node 
class node{
    public:
        int data;
        node *prev;
        node *next;
        node(int x){
            this->data = x;
            this->prev = NULL;
            this->next = NULL;
        }
};
// structure for doubly linked lists methods 
class doubly_linked_list{
    public:
	// inserting at the end 
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
                new_node->prev = ptr;
            
        }
		// displaying the entire list 
        void display(node *&head){
            node *ptr = head;
            if(head == NULL){
                return;
            }
            while(ptr != NULL){
                cout << ptr->data << " ";
                ptr = ptr->next;
            }
            cout << endl;
        }
		// finding the correct position of key and deleting it 
        void deletion(node *&head, int n){
            if(head == NULL){
                return;
            }
            node *ptr = head;
            if(ptr->data == n){
                head = head->next;
                ptr->next->prev = NULL;
                delete ptr;
                return;
            }
            while(ptr->next != NULL){
                if(ptr->next->data == n){
                    break;
                }
                ptr = ptr->next;
            }
            if(ptr->next->next == NULL){
                node *temp = ptr->next;
                ptr->next = NULL;
                delete temp;
                return;
            }
            else{
            node *temp = ptr->next->next;
            delete ptr->next;
            ptr->next = temp;
            temp->prev = ptr;
        }}
		// finding union of two linked lists
		/* logic is to simply transverse for the both lists simultaenously and insert every element of first list in new union lists 
		and delete those in second list which are repeating  and finally in 
		another second pass through second list , insert leftovers all in the new union list.
		*/
        void union_list(node *&head1, node *&head2){
            node *head3 = NULL;
			// if first list is empty 
            if(head1 == NULL){
                node *ptr = head2;
                while(ptr->next != NULL){
                    insertion(head3, ptr->data);
                    ptr = ptr->next;
                }
                return;
            }
			// if second list is empty 
            if(head2 == NULL){
                node *ptr = head1;
                while(ptr->next != NULL){
                    insertion(head3, ptr->data);
                    ptr = ptr->next;
                }
                return;
            }
			// if none of the list is empty 
            node *ptr1 = head1;
            node *ptr2 = head2;
            while(ptr1 != NULL){
                ptr2 = head2;
                insertion(head3, ptr1->data);
                while(ptr2 != NULL){
					// making sure that whenever there is duplicacy of data, then only one of them goes to union of list 
                    if(ptr1->data == ptr2->data){
                        deletion(head2, ptr2->data);
                    }
                    ptr2 = ptr2->next;
                }
                ptr1 = ptr1->next;
            }
			// finally inserting the elemetns of second list which are leftovers after deletion, into union of lists
            ptr2 = head2;
            while(ptr2 != NULL){
                insertion(head3, ptr2->data);
                ptr2 = ptr2->next;
            }
        
            display(head3);
        }
        
};

int main(){
    node *head1 = NULL;
    node *head2 = NULL;
    doubly_linked_list l;
    l.insertion(head1, 10);
    l.insertion(head1, 15);
    l.insertion(head1, 4);
    l.insertion(head1, 20);
    l.display(head1);
    l.insertion(head2, 8);
    l.insertion(head2, 4);
    l.insertion(head2, 2);
    l.insertion(head2, 10);
    l.display(head2);
    l.union_list(head1, head2);
}