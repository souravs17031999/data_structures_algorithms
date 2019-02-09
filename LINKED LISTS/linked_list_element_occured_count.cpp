//program to count the occurences of a given key in the single linked list 
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
	// function to display the data in a linked _list
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
  //function to count the occcurence of a key n in the entire list 
  void occur_count(int n){
      node *ptr = head;
      int count = 0;
      while(ptr != NULL){
          if(ptr->data == n){
              count++;
      }
      ptr = ptr->next;
        }
      cout << n << " occured " << count << " times in the entire list " << endl;}
};
int main(void){
    linked_list a;
    a.insert_node(1);
    a.insert_node(2);
    a.insert_node(1);
    a.insert_node(2);
    a.insert_node(1);
    a.insert_node(3);
    a.insert_node(1);
	//linked list now is : 1->2->1->2->1->3->1
    a.display();
    a.occur_count(1);   // returns 4 for this case 
}
