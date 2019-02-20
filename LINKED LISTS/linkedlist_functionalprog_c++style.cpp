#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
};
node *head = NULL;
void insert(int n){
    node *new_node = new node;
    new_node -> data = n;
    new_node -> next = NULL;
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

void display(){
    node *ptr = head;
    while(ptr != NULL){
        cout << ptr -> data << " ";
        ptr = ptr -> next;
}
}
int main(){
insert(2);
insert(3);
insert(4);
insert(5);
display();
}