#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = prev = NULL;
    }
};

class DoublyList{
    Node* head;
    Node* tail;
public:

    DoublyList(){
        head = tail = NULL;
    }
    void push_front(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void print_dll(){
        Node* temp = head;
        while(temp != NULL)
        {
            cout<< temp->data << " <=> ";
            temp = temp->next;
        }
        cout<<" NULL";
    }
    void push_back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        
    }
    void pop_front(int val){
        head = head->next;
        head->prev = NULL;
        
    }

};

int main(){
    DoublyList dll;
    dll.push_front(1);
    dll.push_front(2);
    dll.push_front(3);
    dll.push_front(4);
    dll.push_front(5);
    dll.push_back(6);
    dll.print_dll();
    
}