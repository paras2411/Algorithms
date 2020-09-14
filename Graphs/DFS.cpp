
#include<bits/stdc++.h>
using namespace std;

/*
Depth First Search is a graph traversing algorithm. It uses stack to 
store the vertices need to be explored. 
We also keep note of which vertex has been visited so that we need
not have to visit it again and fall in an infinite loop.

I am assuming the given graph is a sparse graph. Therefore adjacency 
list is used to store the graph.

If V -> no. of vertices and E -> no of edges then,
its time complexity is O(V+E), since all the vertices are traversed once.
Its space complexity is O(V).
*/

const int N = 1e5;
vector<int> adj[N];
bool visited[N];

// Here we are using recursion method as we know that in recursion,
// stack is used for storing the previous state. 
// u -> current vertex being processed
void dfs(int u){

    visited[u] = true;

    // iterating all the vertices adjacent to u
    for(int v: adj[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}



// We can do dfs using stack itself. This method is iterative.
void dfs2(int u){

    // stack will store the vertices which to be visited. 
    // After any vertex is visited, we add all the adjacent vertices 
    // which need to be visited
    stack<int> traverse;
    traverse.push(u);
    
    // now traverse the graph untill all the vertices are visited
    while(!traverse.empty()){
        
        u = traverse.top();
        traverse.pop();
        visited[u] = true;

        // iterating all the vertices adjacent to u
        for(int v: adj[u]){
            if(!visited[v]){
                traverse.push(v);
            }
        }
    }
}
    