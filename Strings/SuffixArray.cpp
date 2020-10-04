#include<bits/stdc++.h>
using namespace std;
 
/*
Suffix array of a string describes the lexicographic order of its suffixes.

Time complexity - O(n*log(n)). using radix sort for sorting labels
Space complexity - O(n).

string s -> string whose suffix array is calculated
*/
void suffix_array(string s){
 
    int n = s.length();
    int k = (int)(ceil(log2(n)));

    // final label in each round. there are k number of rounds
    vector<int> a(n);
    int c = 1;
    for(char j='a'; j<='z'; j++){
        int inc = 0;
        for(int i=0; i<n; i++){
            if(s[i] == j){
                inc = 1, a[i] = c;
            }
        }
        if(inc){
            c++;
        }
    }

    for(int i=1; i<=k; i++){

        // assign the intial label used to sort the substring
        // initial label use the final label from previous round
        vector<pair<pair<int, int>, int>> b(n);
        int ind = (1<<(i-1));
        for(int j=0; j<n; j++){
            if(j+ind >= n){
                b[j] = {{a[j], 0}, j};
            }
            else{
                b[j] = {{a[j], a[j+ind]}, j};
            }
        }
        // running counting sort on both the part of initial label
        // first on the second part
        vector<vector<pair<int, int>>> cnt(n+1);
        for(int j=0; j<n; j++){
            pair<int, int> par = b[j].first;
            cnt[par.second].push_back({par.first, b[j].second});
        }
        ind = 0;
        for(int j=0; j<=n; j++){
            for(pair<int, int> par: cnt[j]){
                b[ind++] = {{par.first, j}, par.second};
            }
            cnt[j].clear();
        }
        // now on the second part
        for(int j=0; j<n; j++){
            pair<int, int> par = b[j].first;
            cnt[par.first].push_back({par.second, b[j].second});
        }
        
        ind = 0;
        for(int j=0; j<=n; j++){
            for(pair<int, int> par: cnt[j]){
                b[ind++] = {{j, par.first}, par.second};
            }
        }

        // finally assigning the final label on the using the sorted initial label
        ind = 0;
        pair<int, int> prev = {0, 0};
        for(int j=0; j<n; j++){
            pair<int, int> par = b[j].first;
            if(par != prev) ind++;
            a[b[j].second] = ind;
            prev = par;
        }
    }
 
    // suffix array
    vector<int> suff(n);
    for(int i=0; i<n; i++){
        suff[a[i]-1] = i;
    }
    cout << n << " ";
    for(int i=0; i<n; i++){
        cout << suff[i] << " ";
    }
 
}    
 