// program to get the middle of linked list 
// @author sourav kumar , 21-02-2019
#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
};
// class to implement linked list 
class linked_list{
    private:
    node *head;
    public:
    linked_list(){head = NULL;}
    // function to implement insertion of node at the end of linked list
    void insert(int n){
        node *new_node = new node;
        new_node->data = n;
        new_node->next = NULL;
        if(head == NULL){
           head = new_node;
            return;
    }
        node *ptr = head;
    while(ptr->next != NULL){
    ptr = ptr -> next;
}
    ptr -> next = new_node;

}   
	// function to display the linked list 
    void display(){
        if(head == NULL){
            cout << "empty list" << endl;
            return;
        }
        node *ptr = head;
        while(ptr != NULL){
            cout << ptr->data  << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
     	// function to get the middle of a linked list
	/* logic here is that simply keep two pointers one fast and one slow , the fast one moves by two and other two moves by one and then 
	when fast pointer reaches last node , then slow pointer will be at middle node.
	*/
    void middle_list(){
        if(head == NULL){
            cout << "empty list" << endl;
            return;
        }
        node *f = head;
        node *s = head;
        while(f != NULL && f->next != NULL){
            f = f->next->next;
            s = s->next;
        }
        cout << s->data << endl;
    }

};
int main(){
    linked_list l;
    l.display();
    l.middle_list();
}

/* #include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
};
// class to implement linked list 
class linked_list{
    private:
    node *head;
    public:
    linked_list(){head = NULL;}
    // function to get length of a linked list
    int length(){
        if(head == NULL){
            return 0;
    }
        node *ptr = head;
        int count = 0;
        while(ptr != NULL){ // transversung till the last node and incrementing counter by 1 
            count++;
            ptr = ptr->next;
    }
        return count;
    
}	
	// function to get the middle of a linked list 
    int middle_list(int length){
        node *ptr = head;
        if(length % 2 != 0){   // if the list length is odd , just transverse till the middle 
        for(int i = 1; i <= length/2; i++){
            ptr = ptr->next;
        }
        return ptr->data;}
        else{
        for(int i = 1; i <= length/2; i++){  // if the length of list is even , then getting the both nodes but printing only the second node 
            ptr = ptr->next;
        }
            return ptr->data;
        }
    }

    // function to implement insertion of node at thr beginning of linked list
    void insert(int n){
        node *new_node = new node;
        new_node->data = n;
        new_node->next = NULL;
        if(head == NULL){
           head = new_node;
            return;
    }
        node *ptr = head;
        new_node->next = head;
        head = new_node;
}   
	// function to display the linked list 
    void display(){
        node *ptr = head;
        while(ptr != NULL){
            cout << ptr->data  << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }

    
};
int main(){
    linked_list a;
    a.insert(5);
    a.insert(6);
    a.insert(99);
    a.insert(70);
    a.insert(100);
    int length = a.length();  // getting the length of linked list 
    int middle = a.middle_list(length); // getting the middle of linked list 
    a.display();
    cout << middle;
} */
