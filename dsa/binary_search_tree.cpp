#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val){
    if(root == NULL){
        return new Node(val);
    }
    if(val< root->data){
        root->left = insert(root->left, val);
    }
    else{
        root->right = insert(root->right, val);
    }
    return root;
}


Node* buildBST(vector<int> arr){
    Node* root = NULL;

    for(int val: arr){
        root = insert(root, val);
    }
    return root;

}

void inOrder(Node* root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout<< root->data<<" ";
    inOrder(root->right);

}

bool search(Node* root, int key){
    if(root == NULL){
        return false;

    }
    if(root->data == key){
        return true;
    }
    if(root->data >key){
        return search(root->left, key);
    }
    else{
        return search(root->right, key);
    }

}
Node* getInorderSuccessor(Node* root){
    while(root != NULL && root->left != NULL){
        root = root->left;
    }
    return root;
}

Node* delnode(Node* root, int key)
{
    if(root == NULL){
        return NULL;
    }
    if(key< root->data){
        root->left = delnode(root->left, key);
    }
    else if(key> root->data){
        root->right = delnode(root->right, key);
    }
    else{
        if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;        
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else{
            Node* IS = getInorderSuccessor(root->right);
            root->data = IS->data;
            root->right = delnode(root->right, IS->data);

        }
    }
    return root;
}
int main(){
    vector<int> preorder = {5,1,2,8,6,3};
    Node* root = buildBST(preorder);
    cout<<"Before: ";
    inOrder(root);
    cout<<endl;
    bool res = search(root, 9);
    cout<<res<<endl;
    cout<<"After: ";
    delnode(root, 8);
    inOrder(root);
    return 0;
}