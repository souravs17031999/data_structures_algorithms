// program for menu driven flow of fucntions of queue - enqueue , dequeue , display and isempty and isfull
// logic is all same as in other program files in this directory , so no comments :)
// @author sourav kumar , 14-02-2019
#include <iostream>
using namespace std;
#define MAX 10
class queue{
    int front , rear;
    public:
    queue(){
        front = -1;
        rear = -1;
    }
    int arr[MAX];
    void enqueue(int n){
        if(rear == MAX-1){
            cout << "queue overflow" << endl;
            return;
        }
        if(front == -1 && rear == -1){
            front = 0;
            rear = 0;
            arr[rear] = n;
            return;
        }
        rear++;
        arr[rear] = n;
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
        front++;
    }
    void display(){
        if(front == -1 && rear == -1){
            cout << "queue empty" << endl;
            return;
        }
        cout << "printing queue : ";
        for(int i = front; i <= rear; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    int isempty(){
        if(front == -1 && rear == -1){
            return(1);
        }
        return(0);
    }
    int isfull(){
        if(rear == MAX-1){
            return(1);
        }
        return(0);
    }
};
int main(void){
    queue a;
    while(1){
    cout << "press 1 for insertion in queue , 2 for deletion from queue and 3 for display " << endl;
    int t,n;
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
    else{
        cout << "you pressed some wrong key ! try again " << endl;
    }
}
}