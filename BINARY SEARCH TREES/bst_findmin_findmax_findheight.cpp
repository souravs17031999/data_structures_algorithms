// program for implementing findmin , findmax , and findheight functions in a binary search tree using linked lists
// all the logic are written below with the fucntions 
// time complexity of findmin and findmax is 0(h) where height of the tree.
// time complexity of findheight is 0(n) where n is the no of nodes in the bst.
// @author sourav kumar, 07-04-2019
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
            // recursive approach (more intuitive)
            if(root == NULL){
                node *new_node = new node(data);
                root = new_node;
            }
            else if(data <= root->data){
                root->left = insert(root->left, data);
            }
            else{
                root->right = insert(root->right, data);
            }
            return root;
        }	
        // function to search a element in a bst
        string search(node *&root, int key){
        //recursive approach
            if(root == NULL){
                return "NOT FOUND";
            }
            if(root->data == key){
                return "FOUND";
            }
            if(root->data < key){
                return search(root->right, key);
            }
            else{
                return search(root->left, key);
            }
            
        }
		// function for finding minimum in a bst
		// logic is that in a bst , the minimum node will be the leftmost node in a bst and so keep transversing till the left of the leftmost node becomes NULL 
        int findmin(node *&root){
            node *ptr = root;
            while(ptr->left != NULL){
                ptr = ptr->left;
            }
            return ptr->data;
        }
		
		// function for finding maximum in a bst
		// logic is that in a bst , the maximum node will be the rightmost node in a bst and so keep transversing till the right of the rightmost node becomes NULL 
        int findmax(node *&root){
            node *ptr = root;
            while(ptr->right != NULL){
                ptr = ptr->right;
            }
            return ptr->data;
        }
		// function for finding height of the tree
		// since , height is the maximum edges we can cross to reach a leaf node 
		// height of 1 node is 0 
		// logic is that we calc height of left subtree and right subtree and add 1 to get the height of the tree (root) or any node .
        int findheight(node *&root){
            if(root == NULL){
                return -1;
            }
            int leftheight = findheight(root->left);
            int rightheight = findheight(root->right);
            return max(leftheight, rightheight) + 1;
        }
        
        
};
int main(void){
    node *root = NULL;
    binarytree b;
    b.insert(root, 50); 
    b.insert(root, 30); 
    b.insert(root, 20); 
    b.insert(root, 40); 
    b.insert(root, 70); 
    b.insert(root, 60); 
    b.insert(root, 80);
	cout << b.findmin(root) << endl;  // 20
	cout << b.findmax(root) << endl;   // 80
    cout << b.findheight(root);     // 2
}