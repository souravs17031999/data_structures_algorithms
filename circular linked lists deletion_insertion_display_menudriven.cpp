// program for circular lists node deletion from end , insertion and display through menu driven.
// @author sourav kumar , 02-02-2019
#include<iostream>
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
     
    void cir_insert(int n){
    node *new_node = new node;
    new_node->data = n;
    new_node->next = NULL;
    if(head == NULL){
            head = new_node;
            new_node->next = head;
            cout << n << " inserted as head " << endl; 
            return;}

		  node *ptr = head;
    while(ptr->next != head){
            ptr = ptr->next;}
    ptr->next = new_node;
    new_node->next = head;
    cout << n << " inserted at end " << endl;

	}

	// function to display circular linked list 

    void display(){
        if(head == NULL){
            cout << "empty list " << endl;
            return;
            		}
        cout << "circular linked list contains" << endl;
        node *ptr = head;
        do{
            cout << ptr->data << " ";
            ptr = ptr->next;	}

		      while(ptr != head);
        cout << ptr->data;	
        cout << endl;}
    
    void deletion(){
        if(head == NULL){cout << "underflow" << endl;return;}
        node *ptr = head;
        while(ptr->next->next != head){
             ptr = ptr->next;
    }
        node *temp = ptr->next;
        ptr->next = head;
        delete temp;
        
}
    
};
int main(){
    linked_list a;
    int option,data;
    while(1){
    cout << "tell the option : 1 for insertion , 2 for deletion and 3 for just display" << endl;
    cin >> option;
    if(option == 1){
        cout << "enter the data " << endl;
        cin >> data;
        a.cir_insert(data);}
    else if(option == 2){
        a.deletion();
}
    else{
        a.display();
    }}
}
