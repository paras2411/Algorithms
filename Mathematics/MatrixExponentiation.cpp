
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fast_cin ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int mod = 1e9+7;
const int N = 5;

/*
Matrix Exponentiation is used to solve linear recurrence problem. It uses the 
method of modular exponentiation. 

Its time complexity is O(log(p)). Space complexity is O(N^2).

mat -> which stores the final result mat^p
mul -> which is updated everytime exponent is divided by 2
p -> power of which matrix need
*/

void multiply(int a[N][N], int b[N][N]) { 
    
    int mul[N][N]; 
    for (int i = 0; i < N; i++) { 
        for (int j = 0; j < N; j++) { 
            mul[i][j] = 0; 
            for (int k = 0; k < N; k++){
                mul[i][j] += a[i][k]*b[k][j]; 
                mul[i][j] %= mod;
            }
        } 
    } 
  
    for (int i=0; i<N; i++) 
        for (int j=0; j<N; j++) 
            a[i][j] = mul[i][j];  // Updating our matrix 
} 

int power(int F[N][N], int n) {

    int M[N][N];
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            M[i][j] = (i==j)? 1: 0;
        }
    }
    
    while(n > 0){
        
        if(n&1){
            multiply(M, F);
        }
        multiply(F, F);
        
        n /= 2;
    }
    return M[0][0];
} 


int32_t main(){
    
    fast_cin;
    int n;
    int a, b, c, d, e;
    int t;
    cin >> t;
    while(t--){
        cin >> a >> b >> c >> d >> e;
        cin >> n;
        if(n < 5){
            cout << n-1;
            return 0;
        }
        int f[N][N] = {
            {a%mod, b%mod, c%mod, d%mod, e%mod}, 
            {1, 0, 0, 0, 0},
            {0, 1, 0, 0, 0},
            {0, 0, 1, 0, 0}, 
            {0, 0, 0, 1, 0}
        };
        cout << power(f, n-4) << endl;
    }
    return 0;
}