
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> adj[N];
bool vis[N];
int disc[N];
int low[N];
int parent[N];
vector<int> points; // this is articulation point


/*
Articulation point/ cut vertices are those vertices when removed will make the 
graph disconnected. To find the articulation point we use the concept to
track back edge using time.

Time complexity is O(V+E). Space complexity is O(V+E).

u -> vertex being explored {1...n}
*/
void articulation_point(int u){

    static int time = 0;
    int children = 0;
    vis[u] = true;

    disc[u] = low[u] = ++time;

    for(int v: adj[u]){

        if(!vis[v]){
            children++;
            parent[v] = u;
            articulation_point(v);

            low[u] = min(low[v], low[u]);

            // means the root vertex has more than one childeren. therefore
            // when removed will make graph disconnected
            if(parent[u] == 0 && children > 1){
                points.push_back(u);
            }

            // If low of its child is greater than disc of parent then 
            // there is no back edge. therefore disconnected.
            if(parent[u] != 0 && low[v] >= disc[u]){
                points.push_back(u);
            }

        }
        else if(v != parent[u]){
            low[u] = min(low[u], disc[v]);
        }
    }
}