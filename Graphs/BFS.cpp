
#include<bits/stdc++.h>
using namespace std;

/*
Breadth First Search is a graph traversing algorithm. It uses queue to 
store the vertex need to be explored. Because of queue we first visit 
all the adjacent vertex, then go to adjacent of adjacent vertex. In terms
of tree, we first visit all the siblings then go to the child.

We also keep note of which vertex has been visited so that we need
not have to visit it again and fall in an infinite loop.

I am assuming the given graph is a sparse graph. Therefore I will be
using adjacency list to store it.

If V -> no. of vertices and E -> no. of edges then,
its time complexity is O(V+E), since all the vertices and edges are traversed once.
Its space complexity is O(V).
*/

const int N = 1e5;
vector<int> adj[N];
bool visited[N];

// u -> current vertex which is being processed
void bfs(int u){

    queue<int> traverse;
    visited[u] = true;
    traverse.push(u);

    // traverse the graph until all the vertices are visited
    while(!traverse.empty()){

        u = traverse.front();
        traverse.pop();

        // iterate all the adjacent vertices of the currect vertex
        for(int v: adj[u]){
            
            if(!visited[v]){
                visited[v] = true;
                traverse.push(v);
            }
        }
    }
}
