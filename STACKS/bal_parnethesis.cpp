// program for balanced parenthesis , check if the order of all the parenthesis is right 
// @author sourav kumar , 22-02-2019
#include <iostream>
using namespace std;
// class for node 
class node{
    public:
        char data;
        node *link;
};
// class for stack 
class stack{
  private:
    node *top;
  public:
    stack(){
      top = NULL; 
  }
// function for pushing on stack    
  void push_stack(char n){
      node *temp = new node;   
      if(!temp){   
          cout << "stack overflow" << endl;
          return;
      }
      temp->data = n;   
      temp->link = NULL;   
      if(top == NULL){    
          top = temp;
          return;
      }
	 
      temp->link = top;
      top = temp;
  }
 // function for popping from stack 
  char pop_stack(){
      if(top == NULL){    
          cout << "stack underflow" << endl;
          return 'n';
      }
      node *temp = top;
      char r = temp->data;
      top = temp->link;
      delete temp; 
      return r;
  }
  // check if stack is empty 
  bool isempty(){
      if(top == NULL){
          return 1;
      }
      return 0;
  }
   // program for display of stack 
  void display(){
      if(top == NULL){    
          cout << "empty stack" << endl;
          return;
      }
      node *temp = top;
      while(temp != NULL){   
          cout << temp->data; 
          temp = temp->link;    
      }
  }
  // check if order of parenthesis is correct 
  void bal_par(string s){
      int flag = 0;    // setting a flag for checking if the parenthesis is unbalanced 
      for(int i = 0; i <= s.length()-1; i++){   // transversing the string
		  // check if the left parenthesis is it , then push it to the stack 
          if(s[i] == '(' || s[i] == '{' || s[i] == '['){  
              push_stack(s[i]);
            
              }
		  // now the stack should no longer be empty 	  
          if (s.empty()) 
             flag++;      
		 // if there is right parenthesis , then check for individually each type of parenthesis 
          if(s[i] == ')'){
              char p = pop_stack();
              if(p == '{' || p == '['){   // if '(' is popped then there should be '(' so if it is not there , then it is unbalanced
                  flag++;
              }
          }
		  // same for other types of parenthesis 
          else if(s[i] == '}'){
              char p = pop_stack();
              if(p == '[' || p == '('){
                  flag++;
              }
          }
          else if(s[i] == ']'){
              char p = pop_stack();
              if(p == '{' || p == '('){
                  flag++;
              }
          }
          
      }
      if(flag > 0){
          cout << "unbalanced";
          return;
      }
      else{
          cout << "balanced";
          return;
      }
	  // if now there is something left in the stack (left parenthesis ) then it means unbalanced 
      cout << isempty();
  }
};

int main(void){
    stack a; 
    string s = "[()]{}{[()()]()}";  // true 
    a.bal_par(s);
}
