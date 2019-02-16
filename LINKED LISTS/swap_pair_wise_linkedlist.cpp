// program for pair wise swapping in a linked list 
// @author sourav kumar , 16-02-2019
#include <iostream>
#include <algorithm>
using namespace std;
//creating  a structure for linked lists node
struct node{
    int data;
    node *next;
};
//defining a class for all functions for linked list
class linked_list{
    private:
        node *head;    // declaring head node 
    public:
        linked_list(){
            head = NULL;  // initializing head node with null
        }
	// fucntion to insert into a linked list	
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
	// function to display the entire linked list 
    void display(){
        node *ptr;
        ptr = head;
        int count = 0;
        if(ptr == NULL){ // show the warning if empty linked list is said to be displayed
            cout << "empty list" << endl; 
			return;
        }
        while(ptr != NULL){  // transverse the entire linked list and print the data and also increment the ptr to point to next node 
            cout << ptr->data <<" -> ";
            count++;
            ptr = ptr->next;
        }
        cout << endl;
        cout << "linked list contains " << count << " elements" << endl;
    }
	// can be used also instead of STL
    /*void my_swap(int &x, int &y){
        int temp = x;
        x = y;
        y = temp;
    }*/
    void pair_swap(){
        node *ptr = head;
        while(ptr != NULL && ptr->next != NULL){ // transversing the linked list and making sure that it only gets ahead if there is atleast 2 nodes left 
                cout << "current data: " << ptr->data << " next data: " << ptr->next->data << endl;
                swap(ptr->data, ptr->next->data); // using stl function swap 
                cout << "after swapping ";
                cout << "current data: " << ptr->data << " next data: " << ptr->next->data << endl;
                ptr = ptr->next->next;
        }
        
    }
    
    
};
// driver function to test all the other functions 
int main(void){
    linked_list a;
    a.insert(6);
    a.insert(5);
    a.insert(4);
    a.insert(3);
    a.insert(2);
    a.insert(1);
    a.display();  // 1 -> 2 -> 3 -> 4 -> 5 -> 6 ->
    a.pair_swap();
    a.display();  // 2 -> 1 -> 4 -> 3 -> 6 -> 5 -> 
}