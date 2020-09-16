
#include<bits/stdc++.h>
using namespace std;

// mod and prime used to find hash of the string
const int mod = 1e9+9;
const int prime = 31;

// below two function is used to find modInverse of prime
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
int modInverse(int n){
    
    int ans = pwr(n, mod-2);
    return ans;
}
 
/*
Rabin Karp is pattern searching algorithm. In this we matches the hash of 
the pattern with hash of all the substring of pattern size from text. If 
matches then we say pattern exists in the text at this index.

The time complexity is O(max(n, m)). Space complexity is O(1).

s -> text where pattern is searched
p -> pattern to find
*/
void rabin_karp(string s, string p){

    int hash_p = 0;
    int n = s.length();
    int m = p.length();
    int mul = 1;

    // calculating hash of the pattern
    for(int i=0; i<m; i++){

        hash_p += (p[i]-'a'+1)*mul, hash_p %= mod;
        mul *= prime, mul %= mod;
    }

    int hash_s = 0, j = 0;
    mul = 1;

    // modInverse of the prime used which will be multiplied with the
    // old substring hash to find the new substring hash.
    int modI = modInverse(prime);

    // calculating hash for all substring of size m of the text
    for(int i=0; i<n; i++){

        if(i < m){

            hash_s += (s[i]-'a'+1)*mul, hash_s %= mod;
            if(i+1 < m) mul *= prime, mul %= mod;
        }
        else{

            hash_s -= (s[j++]-'a'+1);
            hash_s *= modI, hash_s %= mod;
            hash_s += (s[i]-'a'+1)*mul, hash_s %= mod;
        }

        if(hash_s == hash_p){
            cout << "pattern found at position " << j << endl;
        }
    }
}

