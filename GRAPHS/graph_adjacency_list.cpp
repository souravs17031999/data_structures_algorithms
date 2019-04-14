#include <bits/stdc++.h>
#define nodes 10
using namespace std;
void addedge(vector <int> g[], int u, int v){
    g[u].push_back(v);
    g[v].push_back(u);
}
void printgraph(vector <int> g[]){
    for(int i = 0; i <= nodes - 1; i++){
        cout << "adjacency list of vertex " << i << endl << "head ";
        for(auto x : g[i]){
            cout << " -> " << x;
        }
        cout << endl;
    }
}
int main(void){
    // Your code here
    vector <int> g[nodes];
    addedge(g, 0, 1);
    addedge(g, 2, 4);
    printgraph(g);
}
