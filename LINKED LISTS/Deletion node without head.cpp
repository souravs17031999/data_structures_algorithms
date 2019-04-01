// program is to implement deletion of a given pointer to node without head pointer reference
/* logic is that the simple idea about the location of next node to the node which is to be deleted
, now we can simply copy the next node data to the current pointer given to us and delete next pointer.*/
// time complexity is O(n) where n is no of nodes in the given linked list
// @author sourav kumar , 01-04-2019
#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node(int data){
    this->data = data;
    this->next = NULL;
}
};
class linkedlist{
    public:
    void insert(node *&head, int data){
        node *new_node = new node(data);
        if(head == NULL){
            head = new_node;
            return;
    }
        node *ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next;
    }
        ptr->next = new_node;
}
    void display(node *&head){
        if(head == NULL){
            return;
    }
        node *ptr = head;
        while(ptr != NULL){
            cout << ptr->data << " ";
            ptr = ptr->next;
    }
        cout << endl;
}
    void deletion(node *&ptr){
        if(ptr == NULL){
            return;
    }
        if(ptr->next == NULL){
            delete ptr;
            return;
    }
        node *temp = ptr->next;
        ptr->data = temp->data;
        ptr->next = temp->next;
        delete temp;
        
        
        
}
};
int main(){
    linkedlist l;
    node *head = NULL;
    l.insert(head, 1);
    l.insert(head, 2);
    l.insert(head, 3);
    l.display(head);
    l.deletion(head->next);
    l.display(head);
}
