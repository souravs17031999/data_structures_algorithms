// program to calculate sum of elements of linked lists
// @author sourav kumar , 04-02-2019
#include<iostream>
using namespace std;
// structure for linked list
struct node{
    int data;
    node *next;
};
// class to implement sum and product
class linked_list{
    private:
    node *head;
    public:
    linked_list(){
    head = NULL;}
    // program for implementing insert nodes
    void insert_node(int n){
        node *new_node = new node;
        new_node->data = n;
        new_node->next = NULL;
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
    // program for displaying linked lists
    void display(){
        if(head == NULL){
            cout << "empty list";
            return;
    }
        node *ptr = head;
        while(ptr != NULL){
            cout << ptr->data << "->";
            ptr = ptr->next;
    }
        
}
    // program for implementing sum of element of linked lists
    void sum(){
        int sum = 0;
        node *ptr = head;
        while(ptr->next != NULL){
            sum = sum + ptr->data;
            ptr = ptr->next;
    }
        cout << endl << "sum of elements of linked list is " << sum+ptr->data << endl;
}
    // program for implementing product for elements of linked lists
    void product(){
        int prod = 1;
        node *ptr = head;
        while(ptr != NULL){
            prod = prod*ptr->data;
            ptr = ptr->next;
    }
        cout << "product is " << prod << endl;
}
};
// driver fucntion for calling other functions
int main(){
    linked_list a;
    int t,data;
    cout << "tell no of nodes to insert" << endl;
    cin >> t;
    for(int i = 0; i <= t-1; i++){
        cout << "enter data for node "<< i+1 << endl;
        cin >> data;
        a.insert_node(data);
}
    
    a.display();
    a.sum();
    a.product();
    
}