
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
int tree[N];
int n;

/*
Fenwick tree is a range sum query data structure. It stores sum according 
to the bit of the index. Here tree array is 1-indexed array. 
Add function add the array value at index k to all the index of tree array
which cover this index k. 
Sum function return sum of value in range [1, k]. 

The time complexity of both operation is O(log n). It will be done for array
of n elements. Therefore the time complexity of fenwick tree is O(n).
Space complexity is O(n).

k -> index of array, 
x -> value of the array at that index.
*/
void add(int k, int x){
    while(k <= n){
        tree[k] += x;
        k += k&-k;
    }
}

int sum(int k){
    int total = 0;
    while(k > 0){
        total += tree[k];
        k -= k&-k;
    }
    return total;
}