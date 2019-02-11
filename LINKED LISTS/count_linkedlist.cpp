// program to get the length of linked list 
// @author sourav kumar , 11-02-2019
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
    // function to count the number of elements in a linkedlist
    int length(){
        if(head == NULL){
            return 0;
    }
        node *ptr = head;
        int count = 0;
        while(ptr != NULL){ // transversung tikl the last node and incrementing coubter by 1 
            count++;
            ptr = ptr->next;
    }
        cout << endl;
        return count;
    
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
    
};
int main(){
    linked_list a;
    a.insert(5);
    a.insert(6);
    a.insert(1);
    a.insert(0);
    cout << "no. of elements " << a.length();
}
