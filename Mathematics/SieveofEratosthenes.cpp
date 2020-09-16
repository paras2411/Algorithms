
#include<bits/stdc++.h>
using namespace std;

/*
sieve of eratosthenes is the most efficient method to find all the prime 
numbers less than any number.

Its time complexity is O(n). Space complexity is O(n).

int n -> is the value whose we want to find all the prime numbers less than 
equal to.
*/
void sieve_of_eratosthenes(int n){

    vector<int> primes;
    vector<bool> isprime(n+1, true);
    vector<int> spf(n+1, INT_MAX); // smallest prime factor of that number

    for(int i=0; i<=n; i++){

        // initialising 0 and 1 as non prime
        if(i < 2){
            isprime[i] = false;
            spf[i] = i;
            continue;
        }

        // if prime then push back to the list of primes
        if(isprime[i]){
            primes.push_back(i);
            spf[i] = i;
        }
        int j = 0;

        // checks 1) if current index is not outside of list of primes
        // 2) if the number who we are assigning non prime is not outside the limit
        // 3) current index prime is less than equal to smallest prime factor of
        // that number. Its because the multiple of i will already have spf 
        // equal to less than equal to spf[i].
        // If so then proceed else break
        while(j < (int)primes.size() && (i*primes[j]) <= n && primes[j] <= spf[i]){

            isprime[i*primes[j]] = false;
            spf[i*primes[j]] = primes[j];
            j++;
        }
    }
    for(int prime: primes){
        cout << prime << " ";
    }
    cout << endl;
}

int main(){

    int n;
    cin >> n;
    sieve_of_eratosthenes(n);
    return 0;
}