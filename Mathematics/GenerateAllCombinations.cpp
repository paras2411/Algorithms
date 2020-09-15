
#include<bits/stdc++.h>
using namespace std;

bool next_combination(vector<int>& ind, int n){

    int r = ind.size();
    
    for(int i=0; i<r-1; i++){
        // check if next element has already reached extreme.
        if(ind[i+1] == n-r+i+1){
            ind[i] += 1;
            // if first element is crossed its extreme then we return false
            if(ind[0] == n-r+1){
                return false;
            } 
            for(int j=i+1; j<r; j++){
                ind[j] = ind[j-1]+1;
            }
            return true;
        }
    }
    ind[r-1]++;
    return true;
}

/*
Generating all the r elements combinations possible of an n array elements. 

Its time complexity is O(n*(nCr)). Space complexity is O(n).

vector<int> a -> array elements
r -> no of elements to choose from the array elements
*/
void combinations(vector<int>& a, int r){

    int n = a.size();
    vector<int> index(r);
    iota(index.begin(), index.end(), 0);
    int ans = 0;
    do{
        for(int i=0; i<r; i++){
            cout << a[index[i]] << " ";
        }
        cout << endl;

    }while(next_combination(index, n));
}

int main(){

    int n, r;
    cin >> n >> r;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    combinations(a, r);
    return 0;
}