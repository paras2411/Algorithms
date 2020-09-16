#include<bits/stdc++.h>
using namespace std;

// assuming max size of array to be 1e5
const int N = 1e5;
int n;

/*
Segment tree is a range query data structure. The logic is same as merge sort
logic. Leaf of the tree store the array values. Parent of each node stores
the value according to the problem. If problem asks for sum in a range, then
the parent will store the sum of the values of the child.

Its time complexity is O(n*log(n)). Space complexity is O(n)

st[i].s -> stores the sum of the of the child
*/
struct node{
    int s;
}st[4*N];   // max size of segment tree is 4*size_of_array

/*
update function will update the segment tree whenever any value is changed 
in the array. Initially it assumes array of size n with all values = 0.

Its time complexity is O(log(n)).

cur -> index of the array updated
val -> changed value
i -> index of segment tree
l -> left limit of the index of array covered by ith index segment tree
r -> right limit
*/
void update(int cur, int val, int i=1, int l=0, int r=n-1){

    if(l == r){
        st[i].s = val;
        return;
    }
    int mid = (l+r)/2;

    if(cur <= mid){
        update(cur, val, i*2, l, mid);
    }
    else{
        update(cur, val, i*2+1, mid+1, r);
    }
    st[i].s = st[2*i].s + st[2*i+1].s;
}

/*
query function will take the range value and return the sum of arrya value
in that range. 

Its time complexity is O(log(n)). 

x -> lower limit of range
y -> upper limit of range
i -> index of segment tree
l -> left limit of the index of array covered by ith index segment tree
r -> right limit
*/
int query(int x, int y, int i=1, int l=0, int r=n-1){

    if(x <= l && r <= y){
        return st[i].s;
    } 
    int mid = (l+r)/2;
    int ans = 0;
    if(x <= mid){
        ans += query(x, y, i*2, l, mid);
    }
    if(y > mid){
        ans += query(x, y, i*2+1, mid+1, r);
    }
    return ans;
}
