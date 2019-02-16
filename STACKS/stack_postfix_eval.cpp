// program for evaluation of postfix expression using stacks 
// limitation is that it allows only 4 binary operators - '+' , '-' , '*' , '/' 
// @author sourav kumar , 16-02-2019
#include <iostream>
using namespace std;
#define MAX 1000
// class to implement stack 
class stack{
    int top;
    public:
        stack(){
            top = -1;
        }
        int arr[MAX];
		// fucntion to implement pushing onto the stack 
        void push(int n){
            if(top == MAX-1){
                cout << "stack overflow" << endl;
                return;
            }
            top++;
            arr[top] = n;
        }
		// function to implement popping from stack 
        int pop(){
            if(top == -1){
                cout << "stack underflow" << endl;
                return 0;
            }
            int temp = arr[top];
            top--;
            return temp;
        }
		// function to implement display the stack 
        void display(){
            if(top == -1){
                cout << "empty stack" << endl;
                return;
            }
            cout << "stack: ";
            for(int i = 0; i <= top; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
		// function to evaluate the postfix expression 
        void eval_post_fix(string s){
            int a,b;
            for(int i = 0; i <= s.length() - 1; i++){  // transversing the string
				// check if the digit is operand 
                if(isdigit(s[i])){
                    // for extracting complete digit of a number 
                    int num=0; 
                    while(isdigit(s[i]))  //extract one number at a time 
                    { 
                        num=num*10 + (s[i]-'0');  // this will firstly extract number from character and append the digits of a single number (0 has 48 as ascii value) 
                        i++;   
                    } 
                    i--;   // we have to decrement it because it incremented twice in the last time the while loop terminates
                    push(num);   // pushing the number to the stack   
                    cout << "pushed " << num << endl;
                    display();
                }
				// check if it is the non-digit character 
                else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
                    a = pop();
                    b = pop();
                    cout << "a popped as: " << a << " and b popped as: " << b << endl;
                    display();
					// run addition and push it to stack
                    if(s[i] == '+'){
                        int result = a + b;
                        push(result);
                        cout << "pushed " << result << endl;
                        display();
                    }
					// run subtraction and push it to stack
                    else if(s[i] == '-'){
                        int result = b - a;
                        push(result);
                        cout << "pushed " << result << endl;
                        display();
                    }
					// run product and push it to stack
                    else if(s[i] == '*'){
                        int result = a * b;
                        push(result);
                        cout << "pushed " << result << endl;
                        display();
                    }
					// run divison and push it to stack
                    else if(s[i] == '/'){
                        int result = b / a ;
                        push(result);
                        cout << "pushed " << result <<endl;
                        display();
                    }
                    
                }
            
            }
        
            display();    // finally display the stack 
        }
        
};
// main function to test other functions 
int main(void){
    stack a;
    string s = "100 200 + 2 / 5 * 7 +";
    for(int i = 0; i <= s.length()-1 ; i++){
        cout << s[i] << " ";
    }
    cout << endl;
    a.eval_post_fix(s);  // calling for evaluating post fix expression 
    
}
