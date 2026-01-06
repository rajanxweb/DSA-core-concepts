#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class circularQueue{
public:
    Node* front;
    Node* rear;

    circularQueue(){
        front = rear = NULL;
    }

    void enque(int val){
        Node* newNode = new Node(val);
        if(front == NULL && rear == NULL){
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    void deque(){
        if(front == NULL){
            return;
        }
        Node* temp = front;
        front = front->next;
        if(front == NULL){
            rear = NULL;
        }
        delete temp;
    }
    void peek(){
        if(front == NULL){
            return;
        }
        cout<<front->data<<" ";
    }
        
};

int main(){
    circularQueue c;
    c.enque(10);
    c.enque(20);
    c.enque(30);
    c.enque(40);

    c.peek();
    c.deque();
    c.deque();
    c.peek();
}