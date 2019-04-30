// program for implementing graphs as adjacency list 
// space complexity will be 0(V+E) where V is vertices and E is edges which is a major advantage over adjacency matrix which requires 0(v*v) for v vertices 
/* time complexity depends on data structure used to store the heads of lists created , like here we have used arrays so , adding edge will take 0(V + E) time
and  for checking if edge is there will take 0(V) , and it also depends on implementation of linked lists insertion / deletion of nodes like here we are inserting nodes at the end 
but if we insert at the beginning , then it will further reduce the complexity to 0(1) */ 
// @author sourav kumar , 26-04-2019  
#include <iostream>
using namespace std;
#define MAX 5
// class structure for node 
class node{
    public:
        int data;
        node *next;
        node(int x){
            this->data = x;
            this->next = NULL;
        }
};
// class structure for list 
class list{
    public:
        node *head;
};
// class structure for graph 
class graph{
    public:
		// declaring a array of pointer of type class 'list' which holds the addresses of heads of all lists 
        list *adjlist[MAX];
		// dynamically alloting memory to indices to array and setting each address to NULL
        graph(){
                for(int i = 0; i <= MAX - 1; i++){
                    adjlist[i] = new list;
                    adjlist[i]->head = NULL;
            }
        }
		// function for implementing to create a directed edge between two vertex  considering parameter 'u' as source and 'v' as destination vertex for the graph  
        void adddirectededge(int u, int v){
			// creating a new node containing u as data and setting its next to NULL 
            node *new_node = new node(v);
			// if the source vertex is already empty , then add given destination vertex directly to it 
            if(adjlist[u]->head == NULL){
                adjlist[u]->head = new_node;
                return;
            }
			// otherwise transverse the whole list and add it to the end 
            node *ptr = adjlist[u]->head;
            while(ptr->next != NULL){
                ptr = ptr->next;
            }
            ptr->next = new_node;
        }
		// function for adding undirected edge , which means there is a edge for both sides : source <--> destination 
        void addundirectededge(int u, int v){
            adddirectededge(u, v);
            adddirectededge(v, u);
                
        }
		// fucntion for printing the entire graph 
        void printgraph(){
            for(int i = 0; i <= MAX - 1; i++){
                cout << i << ": ";
                node *ptr = adjlist[i]->head;
                if(ptr == NULL){
                    cout << " NULL ";
                }
                else{
                while(ptr != NULL){
                    cout << ptr->data << " -> ";
                    ptr = ptr->next;
                    if(ptr == NULL){
                        cout << " NULL ";
                    }
                }
                
            }
                cout << endl;
            }
        }
		// function for checking if there is a edge exists or not 
        bool checkedge(int u, int v){
			// if the list is empty for a particular vertex 
            if(adjlist[u]->head == NULL){
                return 0;
            }
			// if not, then traverse the entire list and check it whether the given value of destination vertex matches any already feeded value into any node 
            node *ptr = adjlist[u]->head;
            while(ptr != NULL){
                if(ptr->data == v){
                    return 1;
                }
                ptr = ptr->next;
            }
            return 0;
        }
		// function for removing the edge between given two vertices 
        void removeedge(int u, int v){
            if(adjlist[u]->head == NULL){
                return;
            }
			// if the removed directed edge (vertex) is the first one 
            node *ptr = adjlist[u]->head;
            if(ptr->data == v){
                node *temp = ptr;
                ptr = ptr->next;
                delete temp;
                adjlist[u]->head = ptr;
                return;
            }
			// if not , then locate that vertex and delete it 
            while(ptr->next != NULL){
                if(ptr->next->data == v){
                    node *temp = ptr->next;
                    ptr->next = temp->next;
                    delete temp;
                }
                else{
                ptr = ptr->next;}
            }
        }
		// function for removing undirected edge (vertex) 
		void removeundirectededge(int u, int v){
            removeedge(u, v);
            removeedge(v, u);
        }
};
int main(void){
    // Your code here!
    graph g;
    // here g us mixed graph containing directed and undirected edges both
    g.adddirectededge(0, 1);
    g.adddirectededge(1, 3);
    g.adddirectededge(2, 0);
    g.adddirectededge(3, 4);
    g.adddirectededge(4, 2);
    g.addundirectededge(1, 2);
    g.printgraph();
	cout << endl;
	g.removeundirectededge(1, 2);
	g.printgraph();
    //cout << g.checkedge(1, 3); // 1
    /*cout << endl;
    g.removeedge(1, 3);
    g.printgraph();*/
}
