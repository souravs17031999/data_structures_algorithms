// program for implementing stacks using array
// @author sourav kumar , 30-01-2019
#include <iostream>
using namespace std;
#define MAX 5  // defining a global macro for size of array (fixed)
// implementing stack using class named "stack"
class stack{
    int top;  // declaring a top so that we can keep track of the latest index on the stack 
    public:
    stack(){top = -1;}  // making top as -1 so that first index starts at 0
    int arr[MAX];
	// function to push element to stack at the end 
    void push_stack(int n){     
        if(top >= MAX-1){ 
            cout << "overflow" << endl;  // checking if stack is already full 
        }
        else{
            top++;   // incrementing top to keep track of latest index 
            arr[top] = n;  // assigning the value to the required part of stack
            cout << n << " inserted at " << top << endl;    // printing confirmation message
        }
    }
	// function to pop element from end 
    void pop_stack(){
        if(top < 0){    
            cout << "undeflow" << endl;  // checking if stack is already empty 
        }
        else{
            cout << arr[top] << " removed " << endl;    // confirmed message printing 
            arr[top] = NULL;   // making the removed element value as NULL 
            top--;  // decrementing the top 
            
        }
    }
    // program for displaying the stack
    void display(){
        if(top == -1){
            cout << "empty stack" << endl;
            return;
        }
        for(int i = 0; i <= top; i++){
            cout << arr[i] << " ";
        }
    }
};
// main function to call other functions 
int main(void){
    stack a;  // creating a object of stack class 
	// pushing elements 
    for(int i = 1; i <= 5; i++){
        a.push_stack(i);
    }
	// popping elements 
    for(int i = 1; i <= 5; i++){
        a.pop_stack();
    }
    a.pop_stack();  // underflow 
}
