// all the functions implemented for binary search tree
// @author sourav kumar , 09-04-2019
#include <bits/stdc++.h>
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
        node* findmin(node *&root){
            node *ptr = root;
            while(ptr->left != NULL){
                ptr = ptr->left;
            }
            return ptr;
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
		        q.pop();
		        if(temp->left != NULL){     // checking if left child exist or not , if yes , then push that to the end of queue 
		            q.push(temp->left);
		        }
		        if(temp->right != NULL){   // checking if right child exist or not , if yes , then push that to the end of queue 
		            q.push(temp->right);
		        }
		                          // popping the front of queue 
		    }
		} 
		// function for deletion of node of bst 
		/* first of all , we need to find the node in the bst and then delete it. If it is the leaf node , then simply locate it and delete it . If it has only one child , 
		then locate it and directly link its child to its parent and then delete the node. If it has both children exitsing , then we need to find the min from its right subtree and then replace it with that min value.
		This ensures that no property of bst is voilated , as it is the right one so it is greater than its left subtree , and it is minimum then it is already lesser than its right subtree.
		We can also select max from left subtree of the node to be deleted.
		*/
		node* deletion(node *&root, int data){
		    // it bst is empty 
		    if(root == NULL){
		        return root;
		    }
		    // searching for left side of root in the bst 
		    if(data < root->data){
		        root->left = deletion(root->left, data);
		    }
		    // searching for right side of root in the bst 
		    else if(data > root->data){
		        root->right = deletion(root->right, data);
		    }
		    // the node is found 
		    else{
		        // if no child exits 
		        if(root->left == NULL && root->right == NULL){
		            delete root;
		            root = NULL;
		        }
		        // if only right child exists 
		        else if(root->left == NULL){
		            node *temp = root;
		            root  = root->right;
		            delete temp;
		        }
		        // if only left child exists 
		        else if(root->right == NULL){
		            node *temp = root;
		            root  = root->left;
		            delete temp;
		        }
		        else{
		        // if both of child exits       
		            node *temp = findmin(root->right);  // finding minimum from right subtree of the node to be deleted 
		            root->data = temp->data;     // replacing its data with the min value found 
		            root->right = deletion(root->right, temp->data);   // deleting the deplicate value node  
		        }
		    }
		    return root;
		}
		// function for checking if bst is empty or not
		string isempty(node *&root){
		    if(root == NULL){
		        return "YES";
		    }
		    return "NO";
		}
		// function for calculating sum of all nodes in a bst
		int sum(node *&root){
            	if(root == NULL){
                	return 0;
            	}
            	cout <<  root->data + sum(root->left) + sum(root->right);
            
        	}
		
};	
int main(){
	binarytree b;
	node *root = NULL;
	b.insert(root, 1);
	b.insert(root, 2);
	b.insert(root, 3);
	b.insert(root, 4);
	b.insert(root, 5);
	//b.deletion(root, 3);
        //cout << b.search(root, 3);  // not found 
    	// b.sum(root);  // 15
}
