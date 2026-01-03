#include <iostream>
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

class Stack{
    Node* top;
public:
    Stack(){
        top = NULL;
    }

    void push(int val){
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    int pop(){
        if(top==NULL){
            return -1;
        }
        int poppedItem = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return poppedItem;
    }

    int peek(){
        if(top==NULL){
            return -1;
        }
        return top->data;
    }

    int isEmpty(){
        return top == NULL;
    }
};

int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout<<s.peek()<<endl;
    cout<<s.pop()<<" ";
    cout<<s.pop()<<" ";
    cout<<s.pop()<<" ";
    cout<<s.pop()<<" ";
    cout<<s.pop()<<" ";
    cout<<endl;
    cout<<s.isEmpty();


}