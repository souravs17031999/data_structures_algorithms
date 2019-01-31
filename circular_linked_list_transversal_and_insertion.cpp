//program to insert and display circular list  
//@author sourav kumar  , 31-01-2019

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
  // fucntion to insert node in circular linked last 
  void insert_node(int n){
      node *new_node = new node;
      new_node->data = n;
      new_node->next = NULL;
      if(head == NULL){
          head = new_node;
          new_node->next = head;
          cout << n << " inserted at beginning" << endl;
          return;
        }
      node *ptr = head;
      while(ptr->next != head){
          ptr = ptr->next;
      }
      ptr->next = new_node;
      new_node->next = head;
      cout << n << " inserted at last" << endl;
      }
	 // function to display circular list 
  void display(){
      node *ptr = head;
      if(head == NULL){
          cout << "empty list " << endl;
          return;
      }
	  // so that firstly it display the data and then check the condition hence, displaying in circular fashion 
      do{
          cout << ptr->data << " ";
          ptr = ptr->next;
      }
      while(ptr != head);
      cout << ptr->data;
  }
	
};
int main(void){
    linked_list a;
    a.insert_node(10);
    a.insert_node(20);
    a.insert_node(30);
    a.insert_node(40);
    a.insert_node(50);
    a.display();  // displays 10 20 30 40 50 10
}
