// program for implementing deque : doubly ended queue meaning insertion and deletion can take place at both the ends.
/* logic here to keep track of two pointers front and rear and with the help of it , we can maintain a circular array and rotate front in anticlockwose direction and rear in 
clockwise direction for pushing elements at front and rear ends and opposite of this while popping at both the ends respectively.*/
// all the operations are in 0(1) time complexity.
// @author sourav kumar  , 23-03-2019
#include <iostream>
using namespace std;
#define SIZE 1000
// structure for deque methods 
class deque{
    public:
        int arr[SIZE];
        int front = -1;
        int rear = 0;
		//check whether deque is full or not 
        bool isfull(){
            return ((front == 0 && rear == SIZE-1)|| front == rear+1);
        }
		// check whether deque is empty or not 
        bool isempty(){
            return front == -1;
        }
		//for inserting elements on front side 
        void insertfront(int n){
            if(isfull()){
                return;
            }
			// for very first element 
            if(front == -1) 
            { 
                front = 0; 
                rear = 0; 
            } 
			// if front is 0 then point it to last index (to make it circular)
            if(front == 0){
                front = SIZE - 1;
            }
			// otherwise decrement it 
            else{
                front = front - 1;
            }
			// assign the value 
            arr[front] = n;
        }
		// for inserting elements on rear side 
        void insertrear(int n){
            if(isfull()){
                return;
            }
			// for very first element 
            if(front == -1) 
            { 
                front = 0; 
                rear = 0; 
            }
			//if rear is at end , then point it to first index (to make it circular)
            if(rear == SIZE - 1){
                rear = 0;
            }
			// otherwise increment it 
            else{
                rear = rear + 1;
            }
			// assign the value 
            arr[rear] = n;
        }
		// for deleting the element from front side 
        void deletefront(){
			// check whether the deque is already empty 
            if(isempty()){
                return;
            }
			//when only one element is present 
            if (front == rear) 
            { 
            front = -1; 
            rear = -1; 
            }
			//when front is at last index , point it to first index 
            if(front ==SIZE - 1){
                front = 0;
            }
			// otherwise increment it 
            else{
                front = front + 1;
            }
        }
		// for deleting from rear side 
        void deleterear(){
			//check whether deque is already empty 
            if(isempty()){
                return;
            }
			// when only one element is left in the deque 
            if (front == rear) 
            { 
            front = -1; 
            rear = -1; 
            } 
			// when rear is at 0 , then point it to last index 
            if(rear == 0){
                rear = SIZE - 1;
            }
			//otherwsie decrement it 
            else{
                rear = rear - 1;
            }
        }
		// getting the front of the deque
        void getfront(){
            if(isempty()){
                return;
            }
            cout << "front : " << arr[front] << endl ;
        }
		// getting the rear of the deque 
        void getrear(){
            if(isempty() || rear < 0){
                return;
            }
            cout <<  "rear : " << arr[rear] << endl ;
        }
        
};
int main(void){
    deque q;
    for(int i = 10; i <= 20; i++){
        q.insertfront(i);
    }
    q.insertrear(500);
    q.getfront();
    q.getrear();
	// front : 20
    // rear : 500
}
