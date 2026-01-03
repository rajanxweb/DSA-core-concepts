#include <iostream>
using namespace std;

class Stack{
    int top;
    int capacity;
    int* arr;
public:
    Stack(int size){
        capacity = size;
        top = -1;
        arr = new int[capacity];
    }

    void push(int val){
        if(top == capacity -1){
            return;
        }
        top++;
        arr[top] = val;
    }

    int pop(){
        if(top == -1){
            return -1;
        }
        int removedItem = arr[top];
        top--;
        return removedItem;
    }

    int peek(){
        if(top == -1){
            return -1;
        }
        return arr[top];
    }
    bool isEmpty(){
        return top == -1;
    }
};

int main(){
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    cout<<s.isEmpty()<<endl;
}