// program for reversing kth part from front of queue using stacks as intermediate data structure
// @author sourav kumar , 18-02-2019
#include <iostream>
using namespace std;
#define MAX 1000
// class implementing stack 
class stack{
	int top;
	public:
		stack(){
			top =  -1;
		}
		int arr[MAX];
	// function for pushing the element to the end  of stack 	
	void push(int n){
		if(top == MAX-1){
			cout << "stack overflow " << endl;
			return;
		}
		top++;
		arr[top] = n;
	}	
	// function for popping the element from end of stack 
	int pop(){
		if(top == -1){
			cout << "stack underflow " << endl;
			return 0;
		}
		else{
		int temp = arr[top];
		top--;
		return temp;
		}
	}
	// function for displaying the whole stack 
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
// class implementing queue  
class queue{
    int front;  
    int rear;
    public:
    queue(){front = -1; rear = -1;}   
    int arr[MAX];    
	// function for enqueuing the element to the front of head 
    void enqueue(int n){
        if(rear == MAX-1){   
            cout << "queue overflow" << endl; 
            return;
        }
        if(front == -1 && rear == -1){    
            front++;
            rear++;
            arr[rear] = n;
        }
		
        else{
            rear++;
            arr[rear] = n;   
        }
        
    }
	// function for dequeuing the element from the front and returning from queue 
    int dequeue(){
        if(front == -1 && rear == -1){   
            cout << "queue underflow" << endl;
            return 0;
        }
		
        if(front == rear){
            front = -1;
            rear = -1;
            return 0;
        } 
		 
        int temp = arr[front];
        front++;
        return temp;
    }
	// function for display the queue 
    void display(){
        if(front == -1 && rear == -1){
            cout << "empty queue" << endl;
            return;
        }
        for(int i = front; i <= rear; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
	// function for reversing k part of queue 
    void reverse(int arr[], int n, int k){
		// firstly making a queue taken from user input 
		for(int i = 0; i <=n-1; i++){
			enqueue(arr[i]);
		}
		// pushing the elements of k part of queue to stack 
		stack s;
		for(int i = front; i <= k-1; i++){
		    s.push(arr[i]);
		}
		// popping that part of queue from stack and pushing at the end of queue 
	    for(int i = 0; i <= k-1; i++){
	        int a = s.pop();
	        enqueue(a);
	    }
		// then popping from head of queue (remaining part of queue) and then pushing to end of queue which maintains the relative order of elements of remaining queue 
		// incrementing front so that my focus of front to rear is same as required 
	    front = front + k;
	    for(int i = 0; i <= n-k-1; i++){
	        int a = dequeue();
	        enqueue(a);
	    }
		// final display of reversed queue 
	    display();
    }
};
// main driver function for testing other functions 
int main(void){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	queue q;
	q.reverse(arr,10,6);  // calling reversed queue 
	// output : 6 5 4 3 2 1 7 8 9 10 
}