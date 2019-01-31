// program for firstly creating a linked list of following lists - 10->20->30->40->50->60 and then inserting node 5 at beginning and inserting 35 after node 30 resulting in final linked list containing 5->10->20->30->35->40->50->60
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
  //function to insert a node at position p
  void insert_at(int p, int n){
      node *new_node = new node;
      new_node->data = n;
      new_node->next = NULL;
      node *ptr = head;
      while(ptr != NULL){
          if(ptr->data == p){
              break;
          }
          ptr = ptr->next;
      }
      new_node->next = ptr->next;
      ptr->next = new_node;
      cout << n << " inserted at position " << p << endl;
  }
  // function to insert a node at head 
  void insert_head(int n){
      node *new_node = new node;
      new_node->data = n;
      new_node->next = head;
      head = new_node;
      cout << n << " inserted at beginning " << endl;
  }
  //to display the list 
  void display(){
	  // check if list is empty if yes then return here otherwise transverse the entire list
	  if(head == NULL){     
          cout << "empty list" << endl;
          return;
      }
      node *ptr = head;
      while(ptr != NULL){
          cout << ptr->data << " ";
          ptr = ptr->next;
      }
  }
};
int main(void){
    linked_list a;
	// creating a list : 10->20->30->40->50->60
    for(int i = 6; i >= 1; i--){
        a.insert_head(10*i);
    }
	// inserting 5 at beginning: 5->10->20->30->40->50->60
    a.insert_head(5);
	// inserting 35 after 30 : 5->10->20->30->35->40->50->60
    a.insert_at(30,35);
    a.display();
    
}
