// program for implementing queue through stacks 
/* logic is to simply take the input as array and insert it into queue , now the thing is we have use stack so , push all the elements to stack and then , 
pop out the stack and then again insert the elements into same queue which should also overwrite the previous elements giving us the reversed queue */
// @author sourav kumar , 15-02-2019
#include <iostream>
using namespace std;
#define MAX 1000
// class for implementing stacks 
class stack{
	int top;
	public:
		stack(){
			top =  -1;
		}
		int arr[MAX];
	// fucntion for inserting in the stack (at the end)
	void push(int n){
		if(top == MAX-1){
			cout << "stack overflow " << endl;
			return;
		}
		top++;   
		arr[top] = n;
	}	
	// fucntion for deleting the element from stack (from the end)
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
	// funcntion for displaying the stack 
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
// class for implementing queue 
class queue{
    int front;  
    int rear;
    public:
    queue(){front = -1; rear = -1;}   
    int arr[MAX];    
	// fucntion for insertion at the end of queue 
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
	// program for deletion from the beginning of queue 
    void dequeue(){
        if(front == -1 && rear == -1){   
            cout << "queue underflow" << endl;
            return;
        }
		
        if(front == rear){
            front = -1;
            rear = -1;
            return;
        } 
		 
        arr[front] = NULL;
        front++;
    }
	// function for displaying the queue 
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
	// function for reversing the queue 
    void reverse(int arr[], int n){
		// firstly inserting the input array to queue 
		for(int i = 0; i <=n-1; i++){
			enqueue(arr[i]);
		}
		stack a;
		// then inserting the elements to stack 
		for(int i = 0; i <= n-1; i++){
			a.push(arr[i]);
		}
		// intializing the front and rear to initial values so that new elements enqueued will overwrite the previous one 
		front = -1;
		rear = -1;
		// popping out each element from stack one by one and then enquiqing in the queue 
		for(int i = 0; i <= n-1; i++){
			int p = a.pop();
			enqueue(p);
		}
		// displaying the reversed queue
		display();}
};
// main function for testing other fucntions 
int main(void){
    int n;
    cout << "size of the array: " << endl;
    cin >> n;
    if(n <= MAX){
    int arr[n];
    for(int i = 0; i <= n-1; i++){
    	cin >> arr[i];
	}
	queue q;
	q.reverse(arr,n);}
	else{
		cout << "failure due to overflow of max size" << endl;
	}
	
}