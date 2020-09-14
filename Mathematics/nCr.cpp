
#include<bits/stdc++.h>
using namespace std;

const int mod = 1e+7;

// calculate the factorial of n. n!
int fact(int n){
    int ans = 1;
    for(int i=2; i<=n; i++){
        ans = (ans * i)%mod;
    }
    return ans;
}
 
// calculate the pow(n, r) in O(log r).
int pwr(int n, int r){
    int res = 1;
    while(r > 0){
        if(r&1){
            res = (res * n)%mod;
        }
        n = (n * n)%mod;
        r /= 2;
    }
    return res;
}

// calculate pow(n, -1). Since mod is prime we can use
// pow(n, mod-2) for that.
int modInverse(int n){
    
    int ans = pwr(n, mod-2);
    return ans;
}
 
// Finding gcd as well as x which is inverse of a when mod with b.
int gcd(int a, int b, int *x, int *y){

    if(a == 0){
        *x = 0, *y = 1;
        return b;
    }

    int x1, y1;
    int g = gcd(b%a, a, &x1, &y1);

    *x = y1 - (b/a) * x1;
    *y = x1;

    return g;
}

// calculate pow(n, -1). Here mod is not prime but it is 
// co-prime with n. We are using Extended Euclid Algorithm 
int modInverse2(int n){

    int x, y;
    int g = gcd(n, mod, &x, &y);

    // n and mod are not co-prime.
    if(g != 1){
        cout << "Inverse does not exist";
        return -1;
    }

    int inv = (x%mod + mod)%mod;
    return inv;
}

// Given n different elements, selects r elements at a time. No. of 
// ways to do it, is called combinations. And we denote it by nCr.
int nCr(int n, int r){
    
    int ans = 1;
    for(int i=n-r+1; i<=n; i++){
        ans = (ans * i)%mod;
    }
    int factr = fact(r);
    factr = modInverse(factr);
    ans = (ans * factr)%mod;
    return ans;
}
