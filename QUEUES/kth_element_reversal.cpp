// program for reversing till a given element k , in queue through arrays 
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
	// fucntion to implement dequeue operation - delete the first element from the queue 
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
        cout << "Queue : ";
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
    void reverse(int k){
        if(front == -1 && rear == -1){
            cout << "empty queue , reverse not possible" << endl;
            return;
        }
        for(int i = 0; i <= (k/2)-1; i++){   // transversing till the given position (k) and swapping the values here k/2
            swap(arr[i],arr[k-i-1]);
        }
    }
};
int main(void){
    queue a;
    while(1){
    cout << "press 1 for insertion in queue , 2 for deletion from queue and 3 for display , press 4 for k-th reversal" << endl;
    int t,n,k;
    cin >> t;
    cout << "you pressed " << t << endl;
    if(t == 1){
        cout << "enter the data you wanna insert " << endl;
        cin >> n;
        a.enqueue(n);
    }
    else if(t == 2){
        a.dequeue();
    }
    else if(t == 3){
        a.display();
    }
	// testing the exact requirement of this problem as specified
    else if(t == 4){  
        cout << "how much data you wanna reverse: " << endl;
        cin >> k;
        a.reverse(k);
    }
    else{
        cout << "you pressed some wrong key ! try again " << endl;
    }
}
    
}