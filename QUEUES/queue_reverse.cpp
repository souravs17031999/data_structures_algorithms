// Program for reversing the queue using arrays 
// @author sourav kumar , 14-02-2019
#include <iostream>
using namespace std;
#define MAX 10
// class to implement queue 
class queue{
    int front;  // two variables to keep track of the queue , the queue is from front to rear only 
    int rear;
    public:
    queue(){front = -1; rear = -1;}   // initialize the front and rear 
    int arr[MAX];    
	// fucntion to implement enqueue operation - to add the element to the end  of queue 
    void enqueue(int n){
        if(rear == MAX-1){   // checking if the queue is full 
            cout << "queue overflow" << endl; 
            return;
        }
        if(front == -1 && rear == -1){    // for inserting if the inserted element is first 
            front++;
            rear++;
            arr[rear] = n;
        }
		// otherwise simply increment rear to keep track of end index keeping first to be fixed 
        else{
            rear++;
            arr[rear] = n;   // assigning element to queue 
        }
        
    }
	// function to implement dequeue operation - delete the first element from the queue 
    void dequeue(){
        if(front == -1 && rear == -1){   // checking if the queue is already empty 
            cout << "queue underflow" << endl;
            return;
        }
		// checking if a element only resides in the queue 
        if(front == rear){
            front = -1;
            rear = -1;
            return;
        } 
		// otherwise simply increment the front so that front now points to next element and also assign the removed element as NULL 
        arr[front] = NULL;
        front++;
    }
	// fucntion to display the elements of queue 
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
	// fucntion to swap the values 
    void swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}
	// program for reversing the queue 
    void reverse(){
        int f = front;  // assingning front and rear to some  variables f and r so that we do not lose the reference of the queue 
        int r = rear; 
        int n = (r-f) + 1;   
        for(int i = 0; i <= (n/2)-1; i++){  // transversing till the middle and swapping the values 
            swap(arr[i],arr[n-i-1]);   
        }
    }
};
// driver fucntion to test the other fucntions  
int main(void){
    queue q;
    for(int i = 1; i <= 5; i++){
        q.enqueue(i);
    }
    q.display();
    q.reverse();
    q.display();
}