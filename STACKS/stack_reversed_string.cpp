// program for reversing string using stacks 
// @author sourav kumar , 09-02-2019
#include<iostream>
using namespace std;
#define lim 1000
class stack{
    private:
    int top;
    char arr[lim];
    public:
    stack(){top = -1;}
	// fucntion to push elements to stack 
    void push_stack(char n){
        if(top >= lim){
            cout << "overflow" << endl;
            return;
        }
        top++;
        arr[top] = n;
}
	// fucntion to pop the element from stack 
    char pop_stack(){
        if(top == -1){
            cout << "underflow" << endl;
            return 0;
    }
        char temp = arr[top];
        top--;
        return temp;
}
	// function to display the whole string 
    void display(){
        cout << "string is ";
        for(int i = 0; i <= top; i++){
            cout << arr[i];
    }
        cout << endl;
}
	// function to reverse the string 
    void reverse(string s){
        cout << "reversed string is " << endl;
		// logic is to one by one pop the elments from the stack and push it to the beginning of the string so that whole string reverses 
        for(int i = 0; i <= s.length()-1; i++){
            s[i] = pop_stack();   
            
    }
        cout << s;
        
}
    
};
int main(){
    stack a;
    string s = "sourav";
    for(int i = 0; i <= s.length()-1;i++){
        a.push_stack(s[i]);
    }
        a.display();
        a.reverse(s);
   
},