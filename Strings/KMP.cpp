
#include<bits/stdc++.h>
using namespace std;

vector<int> prefix_function(string s){

    int n = s.length();
    vector<int> pref(n, 0);

    for(int i=1; i<n; i++){
        int j = pref[i-1];
        while(j > 0 && s[i] != s[j]){
            j = pref[j-1];
        }
        if(s[j] == s[i]){
            j++;
        }
        pref[i] = j;
    }
    return pref;
}

/*
KMP(Knuth Morris Pratt) is a pattern searching algorithm. We first find 
the prefix values of the pattern which we uses in the KMP function to 
move the j(current index in pattern) whenever we don't find the character
match. 

Suppose n -> length of text and m -> length of pattern
Its time complexity is O(m+n) and Space complexity is O(m)

string s -> Text, string p -> Pattern
*/
void KMP(string s, string p){

    int n = s.length();
    int m = p.length();

    vector<int> pref = prefix_function(p);
    
    int j = 0;
    for(int i=0; i<n; i++){

        // loop until no valid index or no character match.
        while(i < n && j < m && s[i] == p[j]){
            j++;
            i++;
        }
        // if whole pattern found then print the index
        if(j == m){
            cout << "patter found at index " << i-j << endl;
        }
        // if text still left and j don't point to starting index of pattern
        // and charater is not matched, therefore we move j to previous character
        // of pattern last matching index from prefix function
        if(i != n && j != 0){
            j = pref[j-1];
            i--;
        }
    }
}
