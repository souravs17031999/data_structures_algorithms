#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *left;
    node *right;
    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
}
};
class bst{
    public:
    node* insert(node *&root, int data){
        if(root == NULL){
            node *new_node = new node(data);
            root = new_node;
            return root;
    }
        if(root->data <= data){
            insert(root->right, data);
    }
        else{
            insert(root->left, data);
    }
}
    void inorder(node *&root){
        if(root == NULL){
           return;
    }
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
        
}
    void preorder(node *&root){
        if(root == NULL){
            return;
    }
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
      
}
    void postorder(node *&root){
        if(root == NULL){
            return;
    }
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
}
};
int main(){
    bst b;
    node *root = NULL;
    b.insert(root, 10);
    b.insert(root, 20);
    b.insert(root, 5);
    b.insert(root, 15);
    b.insert(root, 50);
    cout << "inorder: ";
    b.inorder(root);
    cout << endl;
    cout << "preorder: ";
    b.preorder(root);
    cout << endl;
    cout << "postorder: ";
    b.postorder(root);
    
   
}