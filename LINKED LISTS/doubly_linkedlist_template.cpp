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
class doubly_linked_list{
    public:
		// inserting at the end of list 
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
		// printing the list 
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
		// deleting a given key value of node 
        void deletion(node *&head, int n){
            if(head == NULL){
                return;
            }
			// if the key is the first node 
            node *ptr = head;
            if(ptr->data == n){
                head = head->next;
                ptr->next->prev = NULL;
                delete ptr;
                return;
            }
			// searching for it in the entire list 
            while(ptr->next != NULL){
                if(ptr->next->data == n){
                    break;
                }
                ptr = ptr->next;
            }
			// if the key is the last node 
            if(ptr->next->next == NULL){
                node *temp = ptr->next;
                ptr->next = NULL;
                delete temp;
                return;
            }
			// if it is somewhere in between 
            else{
            node *temp = ptr->next->next;
            delete ptr->next;
            ptr->next = temp;
            temp->prev = ptr;
        }}
};

int main(){
    node *head1 = NULL;
    doubly_linked_list l;
    for(int i = 1; i <= 5; i++){
        l.insertion(head1, i);
    }
    l.display(head1);
    l.deletion(head1, 4);
    l.display(head1);
}