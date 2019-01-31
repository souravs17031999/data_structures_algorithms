//program to create circular linked list and then insert at first , last and a given element of position
// @author sourav kumar , 31-01-2019
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
  // fucntion to insert at head of circular linked_list 
  void insert_head(int n){
      node *new_node = new node;
      new_node->data = n;
      new_node->next = NULL;
      if(head == NULL){
        cout << "empty list , thus making this new node as head" << endl;
        head = new_node;
        new_node->next = head;
        return;
      }
      new_node->next = head;
      head = new_node;
      node *ptr = head;  
	  // transversing till the end 
      while(ptr != ptr->next){   // since the earlier inserted element is pointing to itsef and hence the condition in while loop
          ptr = ptr->next;
    }
     ptr->next = head;                                          
      
  }
  // fucntiont to insert at last of circular linked list
  void insert_last(int n){
      node *new_node = new node;
      new_node->data = n;
      new_node->next = NULL;
      if(head == NULL){
        cout << "empty list , thus making this last node as the head" << endl;  
        head = new_node;
        new_node->next = head;
        return;
      }
      node *ptr = head;
      while(ptr->next != head){
          ptr = ptr->next;
      }
      ptr->next = new_node;
      new_node->next = head;
  }
  // function to insert a node p after a given position at n of element 
  void insert_at(int n, int p){
      node *new_node = new node;
      new_node->data = p;
      new_node->next = NULL;
      node *temp;
      node *ptr = head;
      while(ptr->next != head){
          if(ptr->data == n){
              temp = ptr->next;
              break;
          }
          ptr = ptr->next;
      }
      ptr->next = new_node;
      new_node->next = temp;
  }
   // function to display the linked list
  void display(){
      node *ptr = head;
      if(head == NULL){
          cout << "empty list " << endl;
          return;
      }
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
    a.insert_head(10);
    a.insert_last(20);
    a.insert_last(40);
    a.insert_at(20,30);
    a.insert_at(40,90);
    a.display();   // 10->20->30->40->90->10
}
