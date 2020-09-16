
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+1;
vector<pair<int, int>> adj[N]; // {v, w} way it should be stored
int n;

/*
Dijkstra is single source shortest path algorithm. It finds distance of 
a single vertex to all other vertex. Logic is similar to Prim MST algo.

Its time complexity is O(E log(V)). Its space complexity is O(E).

source -> vertex whose distance need to find from all other vertex
*/
void dijkstra(int source){

    vector<int> distance(n+1, INT_MAX);  // change INT_MAX to LLONG_MAX if dealing long integers
    // negative weight will be stored because it will sort the weight in 
    // decreaing order
    priority_queue<pair<int, int>>pq;  // {-w, u}
    pq.push({0, source});
    distance[source] = 0;

    while(!pq.empty()){
        pair<int, int> top = pq.top();
        pq.pop();
        int u = top.second;
        // if distance of u is less than the current distance extracted 
        // from pq, it means no need to explore adjacent vertex
        if(-top.first > distance[u]) continue;

        for(pair<int, int> p: adj[u]){
            
            int v = p.first;
            int w = p.second;
            // push vertex to pq because we have found some path whose 
            // distance is less than previous distance
            if(distance[u]+w < distance[v]){
                distance[v] = distance[u]+w;
                pq.push({-distance[v], v});
            }
        }
    }
    for(int i=1; i<=n; i++){
        cout << distance[i] << " ";
    }
    cout << endl;
}

