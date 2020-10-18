#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n";

const int N = 2e5+2;
ll a[N];
int n, q;

struct node{
    ll sm, lz;
}st[1<<19];

void app(int i, ll x, int l2, int r2){
    st[i].sm += x*(r2-l2+1);
    st[i].lz += x;
}

void psh(int i, int l2, int m2, int r2){
    app(i*2, st[i].lz, l2, m2);
    app(i*2+1, st[i].lz, m2+1, r2);
    st[i].lz = 0ll;
}


void update(int l1, int r1, ll x, int i=1, int l2=0, int r2=n-1){
    if(l1<=l2 && r1>=r2){
        app(i, x, l2, r2);
        return;
    }
    int m2 = (l2+r2)/2;
    psh(i, l2, m2, r2);
    if(l1 <= m2)
        update(l1, r1, x, i*2, l2, m2);
    if(m2 < r1)
        update(l1, r1, x, i*2+1, m2+1, r2);

    st[i].sm = st[i*2].sm + st[i*2+1].sm;
}

ll query(int l1, int r1, int i=1, int l2=0, int r2=n-1){
    if(l1<=l2 && r2<=r1){
        return st[i].sm;
    }
    int m2 = (l2 + r2)/2;
    psh(i, l2, m2, r2);
    ll ans = 0;
    if(l1 <= m2)
        ans += query(l1, r1, i*2, l2, m2);
    if(m2 < r1)
        ans += query(l1, r1, i*2+1, m2+1, r2);

    return ans;
}

void solve(){

    cin >> n >> q;
    for(int i=0; i<n; i++){
        cin >> a[i];
        update(i, i, a[i]);
    }
    int l, r, type;
    ll x;
    while(q--){
        cin >> type;
        if(type == 1){
            cin >> l >> r >> x;
            l--, r--;
            update(l, r, x);
        }
        else{
            cin >> l;
            l--;
            cout << query(l, l) << endl;
        }
    }
}

int32_t main(){

    solve();
    cout << endl;

    return 0;
}
