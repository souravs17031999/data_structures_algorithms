// program for implementing circular queue using arrays 
// @author sourav kumar , 09-02-2019
// logic is same as normal queue , just in this case wherever we need to increment to next index we use i -> (i + 1) % MAX [where earlier we used , i - > i + 1]
#include <iostream>
using namespace std;
#define MAX 10
class cir_queue{
    int front;
    int rear;
    public:
    cir_queue(){front = -1; rear = -1;}
    int arr[MAX];
    void enqueue(int n){
        if((rear + 1) % MAX == front){
            cout << "queue overflow" << endl;
            return;
        }
        if(front == -1 && rear == -1){
            front = 0;
            rear = 0;
            arr[rear] = n;
        }
        else{
            rear = (rear + 1) % MAX;
            arr[rear] = n;
        }
        
    }
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
        front = (front + 1) % MAX;
    }
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
};
int main(void){
    cir_queue q;
    for(int i = 10; i <= 19; i++){
        q.enqueue(i);
    }
    q.display();
    q.dequeue();
    q.dequeue();
    q.display();
}
