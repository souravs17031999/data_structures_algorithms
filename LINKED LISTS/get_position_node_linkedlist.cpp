// program to get the length of linked list 
// @author sourav kumar , 12-02-2019
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
    linked_list(){head = NULL;}
    // function to get the index (position) of node (element) in a linkedlist
    void get_position(int n){
        node *ptr = head;
        int index =  0;
        while(ptr != NULL){
            
            if(ptr->data == n){
                break;
            }
            index++;
            ptr = ptr->next;
        }
        cout << "the index " << " for element " << n << " is " << index;
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
        
        new_node->next = head;
        head = new_node;
}
    
};
int main(){
    linked_list a;
    a.insert(5);
    a.insert(6);
    a.insert(1);
    a.insert(0);
    a.get_position(5);
}