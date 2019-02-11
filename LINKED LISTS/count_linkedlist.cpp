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
    int length(){
        if(head == NULL){
            return 0;
    }
        node *ptr = head;
        int count = 0;
        while(ptr != NULL){
            count++;
            ptr = ptr->next;
    }
        cout << endl;
        return count;
    
}
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