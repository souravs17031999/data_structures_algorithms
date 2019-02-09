// program for deletion of linked_list at first , last and at some given element
// @author sourav kumar, 31-01-2019
#include <iostream>
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
  // function to insert nodes in a linked_list 
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
	 // function to display the nodes in linked_list  
  void display(){
      node *ptr = head;
      if(head == NULL){
          cout << "empty list " << endl;
          return;
      }
      while(ptr != NULL){
          cout << ptr->data << " ";
          ptr = ptr->next;
      }
      cout << endl;
  }
  //function to delete the first node 
  void deletion_head(){
      if(head == NULL){   // checking if the list is empty 
          cout << "empty list not able to delete " << endl;
          return;
      }
      node *ptr = head;
      head = ptr->next;
      cout << ptr->data << " deleted from beginning " << endl;
      delete ptr;
      
  }
  //function to delete the last node 
  void deletion_last(){
      if(head == NULL){
          cout << "empty list not able to delete " << endl;
          return;
      }
      node *ptr = head;
      while(ptr->next->next != NULL){
          ptr = ptr->next;
      }
      delete ptr->next;
      ptr->next = NULL;
  }
  //function to delete at given node element n 
  void deletion_at(int n){
      node *ptr = head;
      node *temp;
      while(ptr != NULL){
          if(ptr->next->data == n){
              temp = ptr->next->next;
              break;
          }
          ptr = ptr->next;
      }
      delete ptr->next;
      ptr->next = temp;
      
      
  }
  
};
int main(void){
    linked_list a;
    for(int i = 1; i <= 6; i++){
        a.insert_node(10*i);
    }
    a.display();
	a.deletion_last();
	a.deletion_head();
    a.deletion_at(40);
    a.display();
}
