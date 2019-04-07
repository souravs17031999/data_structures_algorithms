// program for implementing binary search trees using linked lists - insertion and search 
// basic idea of bst  ->  each parent can have atmost 2 children (nodes ) and the element left of root node will be lesser and right will be greater than root node.
// this follows for every node as every node can be parent node for sub trees inside a bst.
// thus , each subtree must follow the logic of bst
// here , time complexity of all the operations like insertion, searching and deletion of node takes 0(lg(n)) time.
// @author sourav kumar , 07-04-2019
#include <iostream>
using namespace std;
// class structure for node 
class node{
    public:
        int data;
        node *left;
        node *right;
        node(int x){
            this->data = x;
            this->left = NULL;
            this->right = NULL;
        }
};
// class structure for methods of bst 
class binarytree{
    public:
		// function for inserting a new node in bst 
		// logic is that new node is always inserted after a leaf node 
        node* insert(node *&root, int data){
            node *new_node = new node(data);    // creating  a new node with data 
            node *ptr = root;     // creating a pointer to transverse the whole tree down 
            node *temp = NULL;    // creating  a pointer to keep a tail of above pointer so that it points always to the leaf node 
            while(ptr != NULL){   // transverse till we hit leaf node  
                temp = ptr;       // keeping the copy of last visited node 
                if(data < ptr->data){    // transversing left of tree 
                    ptr = ptr->left;
                }
                else{
                    ptr = ptr->right;     // transversing right of tree 
                }
            }
			// now we have temp ptr pointing to the leaf node and based on the conditions we can insert the new node linked to the leaf node found 
            if(temp == NULL){
                temp = new_node;
            }
            else if(data < temp->data){
                temp->left = new_node;
            }
            else{
                temp->right = new_node;
            }
            return temp;
        }
            // recursive approach (more intuitive)
            /*if(root == NULL){
                node *new_node = new node(data);
                root = new_node;
            }
            else if(data <= root->data){
                root->left = insert(root->left, data);
            }
            else{
                root->right = insert(root->right, data);
            }
            return root;*/
			
        // function to search a element in a bst
        string search(node *&root, int key){
			// transverse down whole tree till we hit a leaf node (nothing found)
            while(root != NULL){
                if(key < root->data){   // going to the left of tree 
                    root = root->left;
                }
                else if(key > root->data){  // going to the right of tree 
                    root = root->right;
                }
                else{
                    return "FOUND";      // otherwise found 
                }
            }
            return "NOT FOUND";     // reached here , when not found 
        }
        //recursive approach
        /*if(root == NULL || root->data == key){
                return root;
            }
            if(root->data < key){
                return search(root->right, key);
            }
            else{
                return search(root->left, key);
            }*/
};
int main(void){
    node *root = NULL;
    binarytree b;
    root = b.insert(root, 50); 
    b.insert(root, 30); 
    b.insert(root, 20); 
    b.insert(root, 40); 
    b.insert(root, 70); 
    b.insert(root, 60); 
    b.insert(root, 80); 
    cout << b.search(root, 100); // not found
	cout << b.search(root, 70);  // found
    
}
