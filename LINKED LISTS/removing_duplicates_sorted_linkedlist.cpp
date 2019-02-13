// program for removing duplicates in a sorted linked list 
// @author sourav kumar , 13-02-2019
// logic except del_dup is same as in other files so , no comments for that :)
#include <iostream>
using namespace std;
struct node{
  int data;
  node *next;
};
class linked_list{
  node *head;
  public:
  linked_list(){
      head = NULL;
  }
  void del_dup(){
      node *ptr = head;
      node *temp;
	  // logic is to check if the match occurs (duplicate found) then delete the next one node otherwise increment the pointer 
      while(ptr->next != NULL){   // transversing just before end 
          if(ptr->data == ptr->next->data){  // checking the condition so that after match we delete the next one node 
              temp = ptr->next->next;  // keeping the address of the node to be deleted 
              delete ptr->next;  // destroying the next one node (duplicate of the current one)
              ptr->next = temp;  // linking the current node to the node after just deleted node 
              
          }
          else{
          ptr = ptr->next;}   // if no match , then increase the ptr 
      }
  }
  void insert_beg(int n){
      node *new_node  = new node;
      new_node->data = n;
      new_node->next = NULL;
      if(head == NULL){
          head = new_node;
          return;
      }
      new_node->next = head;
      head = new_node;
  }
  void display(){
      if(head == NULL){
          cout << "empty list" << endl;
          return;
      }
      node *ptr = head;
      while(ptr != NULL){
          cout << ptr->data << "->";
          ptr = ptr->next;
      }
  }
};
int main(void){
    linked_list a;
    a.insert_beg(60);
    a.insert_beg(43);
    a.insert_beg(43);
    a.insert_beg(21);
    a.insert_beg(11);
    a.insert_beg(11);
    a.insert_beg(11);
    
    a.display();
    a.del_dup();
    cout << endl;
    a.display();
    
}
