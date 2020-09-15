
#include<bits/stdc++.h>
using namespace std;

// considering maximum no. of vertices to be 1000. Prim is better than kruskal
// when the graph is a dense graph. Here we are assuming graph is dense graph
const int N = 1e3;
vector<pair<int, int>> adj[N]; // {v, w}

/*
Prim is the algrithm to find minimum spanning tree. It is using priority queue
to get the minimum value of edges from any vertex. Then that min value is
added to the cost of MST if that vertex is not added. Otherwise ignored. 

Its time complexity is O(E log(V)). Space complexity is (E).

n -> no. of vertices (V)
*/
void prim(int n){
    
    // Keeps note of the current minvalue noted for the vertex. So that 
    // we need not have to consider edges from this vertex having higher 
    // value than this min_cost[v]
    vector<int> min_cost(n, INT_MAX);

    // keeps note of vertices included in MST
    vector<bool> visited(n, false);

    // stores the edges who are candidates to be added to the MST. We are 
    // getting the minimum value edge and checking if its correspoding 
    // vertex is not added to the MST.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    // cnt_vertices stores how many vertices has been added
    int cost_MST = 0, cnt_vertices = 0;

    while(!pq.empty()){

        pair<int, int> top = pq.top();
        pq.pop();
        int u = top.second;
        // If vertex is already included in MST, then continue 
        if(visited[u]){
            continue;
        }

        cnt_vertices += 1;
        cost_MST += top.first;
        visited[u] = true;
        // If all vertices are added we break
        if(cnt_vertices == n){
            break;
        }

        for(auto it: adj[u]){

            int v = it.first;
            int w = it.second;
            // If vertex is not added to MST and its edge has value lower 
            // than the current present in priority queue then its added
            if(!visited[v] && w < min_cost[v]){
                pq.push({w, v});
                min_cost[v] = w;
            }
        }
    }
}




