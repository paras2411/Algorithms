#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> adj[N], tr[N];
int vis[N];
stack<int> st;

void dfs(int u){

    vis[u] = 1;
    for(int v: adj[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
    st.push(u);
}

/*
Kosaraju's Algorithm is used to find the strongly connected components
in a directed graph. It used transpose of the original graph for finding 
the components.
1) Build a stack which contains vertices in the order that all the connections
of the bottom one is visted first.
2) Extract the top of stack and the start the dfs on the transpose graph.

Its time complexity is O(V+E).

u -> starting vertex
*/
void SCC(int u){

    vector<vector<int>> components;
    
    //running dfs on original graph to build the stack
    dfs(u);
    memset(vis, 0, sizeof(vis));
    
    while(!st.empty()){

        u = st.top();
        st.pop();
        if(vis[u]) continue;

        vector<int> members;
        stack<int> st2;

        st2.push(u);
        vis[u] = 1;
        members.push_back(u);

        //find all the members of that component
        while(!st2.empty()){
            
            u = st2.top();
            st2.pop();
            
            for(int v: tr[u]){

                if(!vis[v]){
                    vis[v] = 1;
                    members.push_back(v);
                    st2.push(v);
                }
            }
        }

        components.push_back(members);
    }
    cout << components.size() << endl;
    for(auto vi: components){
        for(int mi: vi){
            cout << mi << " ";
        }
        cout << endl;
    }
}


int main(){

    int n, m;
    cin >> n >> m;
    int u, v;
    for(int i=0; i<m; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        tr[v].push_back(u);
    }
    SCC(0);
    return 0;
}