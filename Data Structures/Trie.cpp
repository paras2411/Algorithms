
#include<bits/stdc++.h>
using namespace std;

// Defining the node contents of the trie
typedef struct node{
    int val;
    node* nxt[26];
}trie;

int n, k;

// Initialising/creating the node
void insert(int i, string& s, trie* root){
    
    if(i == s.length()){
        return;
    }
    int ind = s[i] - 'A';

    // If node not exists then create 
    if(!root->nxt[ind]){
        root->nxt[ind] = new trie();
    }
    root->nxt[ind]->val += 1;
    insert(i+1, s, root->nxt[ind]);
}


int main(){
    string s;
    cin >> n >> k;
    trie *root = new trie();
    for(int i=0; i<n; i++){
        cin >> s;
        insert(0, s, root);
    }
}
