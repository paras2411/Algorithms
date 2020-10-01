
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int BLOCK = 448;
const ll MOD = 1000000007;
const int N = 2e5 + 5;
int a[N];
ll ans[N];

int n, t;
int mp[1000005];

struct node{
    int l, r, i;
} q[N];

ll cur_ans = 0;
bool cmp(node x, node y){

    if(x.l/BLOCK != y.l/BLOCK){
        return x.l/BLOCK < y.l/BLOCK;
    }
    return x.r < y.r;
}

void add(int x){
    // Implement add logic
}

void remove(int x){
    // Implement remove logic
}

void solve(){

    sort(q, q+t, cmp);

    int current_l = 0, current_r = 0;
    for(int i=0; i<t; i++){

        while(current_l < q[i].l){
            remove(current_l);
            current_l++;
        }
        while(current_l > q[i].l){
            add(current_l-1);
            current_l--;
        }
        while(current_r <= q[i].r){
            add(current_r);
            current_r++;
        }
        while(current_r > q[i].r+1){
            remove(current_r-1);
            current_r--;
        }
        int index = q[i].i;
        ans[index] = cur_ans;
    }

    for(int i=0; i<t; i++)
		cout << ans[i] << "\n";

}