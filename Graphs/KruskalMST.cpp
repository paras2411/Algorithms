
#include<bits/stdc++.h>
using namespace std;

// considering maximum no. of vertices to be 100000.
const int N = 1e5;
int parent[N];

// find the root(ancestor) of the vertex u and returns the no. of vertices in that path
int findpar(int *u){

    int rank = 0;
    while(*u != parent[*u]){
        *u = parent[*u];
        rank++;
    }
    return rank;
}

/*
Kruskal is the algrithm to find minimum spanning tree. It takes list
of sorted edges wrt to weight. Then iterate that list and add that 
edge which do not form cycle with the added edges. For checking the 
cycle we are using "Disjoint set Union" method. 

Its time complexity is O(E log(E)). Space complexity is (V+E).

vector<pair<int, pair<int, int>>> edges -> list of edges with weights w {w, {u, v}}
n -> no. of vertices (V)
*/
void kruskal(vector<pair<int, pair<int, int>>> edges, int n){

    // sorting that list of edges with weights 
    sort(edges.begin(), edges.end());

    // assigning each vertices to be its parent
    for(int i=0; i<n; i++){
        parent[i] = i;
    }

    // cost -> sum of all the weights of the edges added to the MST
    int cost = 0;
    int edg_count = 0; // should be n-1 after iteration (Tree)

    for(auto it = edges.begin(); it != edges.end() && edg_count < n-1; it++){
        
        int weight = (*it).first;
        pair<int, int> edge = (*it).second;

        int u = edge.first, v = edge.second;
        
        // find the root ancestor of the both vertex and its rank as well
        int rank_u = findpar(&u);
        int rank_v = findpar(&v);

        // If root different then adding this edge will not form cycle.
        if(u != v){

            cost += weight;
            edg_count += 1;
            
            // making root ancestor of both vertex same.
            if(rank_u < rank_v){
                parent[u] = v;
            }
            else{
                parent[v] = u;
            }
        }

    }

}
