#include <bits/stdc++.h>
using namespace std;
// class structure for node 
class node{
    public:
        char data;
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
        node* insert(node *&root, char data){
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
		// we make a queue for storing references (address) of children nodes and then maintain that order for which first come first out idea serves here 
		// time complexity is 0(n) where n is number of nodes in a bst as we keep moving through each node and queue operations takes 0(1) time.
		// space complexity is 0(n) which mostly depends on queue elements size 
		void levelorder(node *&root){
		    if(root == NULL){
		        return;
		    }
		    queue <node *> q;    // using stl container for queue of pointer type 
		    q.push(root);    
		    while(!q.empty()){              
		        node *temp = q.front();     // calling the front of queue 
		        cout << temp->data << " ";  // printing the data of the node at current 
		        if(temp->left != NULL){     // checking if left child exist or not , if yes , then push that to the end of queue 
		            q.push(temp->left);
		        }
		        if(temp->right != NULL){   // checking if right child exist or not , if yes , then push that to the end of queue 
		            q.push(temp->right);
		        }
		        q.pop();                  // popping the front of queue 
		    }
		}
		
		
};	
int main(){
	binarytree b;
	node *root = NULL;
	b.insert(root, 'F');
	b.insert(root, 'D');
	b.insert(root, 'J');
	b.insert(root, 'B');
	b.insert(root, 'E');
	b.insert(root, 'G');
	b.insert(root, 'K');
	b.insert(root, 'A');
	b.insert(root, 'C');
	b.insert(root, 'I');
	b.insert(root, 'H');
	b.levelorder(root);
}