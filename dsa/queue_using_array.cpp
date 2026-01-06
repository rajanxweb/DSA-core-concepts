#include <iostream>
using namespace std;

class circulaQueue{
    int* arr;
    int size;
    int front;
    int rear;
public:
    circulaQueue(int s){
        size = s;
        front = -1;
        rear = -1;
        arr = new int[size];
    }

    void enque(int val){
        if((rear + 1)%size == front){
            return;
        }
        if(front == -1){
            front = 0;
        }
        rear = (rear + 1)%size;
        arr[rear] = val;
    }

    void deque(){
        if(front == -1){
            return;
        }
        int data = arr[front];

        if(front == rear){
            front = -1;
            rear = -1;
        }
        else{
            front = (front + 1)%size;
        }
        
    }
    void peek(){
        cout << arr[front]<<endl;
    }
    bool isEmpty(){
        return front == -1;
    }


};

int main(){

    circulaQueue c(5);
    c.enque(1);
    c.peek();
    c.deque();
    c.peek();



}