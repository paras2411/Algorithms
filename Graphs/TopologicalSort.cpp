
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> adj[N];
int state[N];
vector<int> topo_sort;
bool cycle = false;

/*
Topological sort is an ordering of nodes in a directed graph such that if
node a has directed edge to b, then in this order a comes before b. Topological
sort exists if the graph is acyclic. 

Its time complexity is O(V+E). Its space complexity is O(V+E).

u -> vertex being explored
*/
void topological_sort(int u){

    state[u] = 1;
    for(int v: adj[u]){
        if(state[v] == 1 || cycle){
            cycle = true;
            return;
        }
        if(state[v] == 0) topological_sort(v);
    }
    state[u] = 2;
    topo_sort.push_back(u);
}

