#include <iostream>
using namespace std;
//singly linked-list
class Node{
public: 
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

class List{
    Node* head;
    Node* tail;
public:
    List(){
        head = tail = NULL;
    }
    void push_front(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            return;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }

    void print_list(){
        Node* temp = head;
        while(temp != NULL){
            cout<< temp->data <<" ";
            temp = temp->next;
        }
    }

    void push_back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->next = NULL;
        tail = newNode;
    }

    void pop_front(){
        if(head==NULL){
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    void pop_back(){
        if(head == NULL){
            return;
        }
        Node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        temp->next = tail;
        delete tail;
        tail = temp;
    }

    void insert_pos(int val, int pos){
        Node* newNode = new Node(val);
        if(pos ==0){
            head = newNode;
            return;
        }
        Node* temp = head;
        for(int i=0; i<pos-1; i++){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    int search(int key){
        Node* temp = head;
        int idx = 0;
        while(temp != NULL){
            if(temp->data == key){
                return idx;
            }
            temp = temp->next;
            idx++;
        }
    }
};

int main(){

    List ll;

    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);
    ll.push_front(5);
    ll.push_back(0);
    ll.pop_front();
    ll.insert_pos(3,2);
    int result = ll.search(0);
    cout<<result <<endl;

    ll.print_list();


}




