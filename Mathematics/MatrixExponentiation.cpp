
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
void pwr(int (&mat)[N][N], int mul[N][N], int p){

    while(p > 0){
        int cur[N][N];
        if(p&1){
            for(int i=0; i<N; i++){
                for(int j=0; j<N; j++){
                    cur[i][j] = 0;
                    for(int k=0; k<N; k++){
                        cur[i][j] += (mat[i][k]*mul[k][j])%mod;
                        cur[i][j] %= mod;
                    }
                }
            }
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                mat[i][j] = cur[i][j];
            }
        }
        
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cur[i][j] = 0;
                for(int k=0; k<N; k++){
                    cur[i][j] += (mul[i][k]*mul[k][j])%mod;
                    cur[i][j] %= mod;
                }
            }
        }

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                mul[i][j] = cur[i][j];
            }
        }

        p /= 2;
    }
}

int32_t main(){
    
    fast_cin;
    int t;
    cin >> t;
    while(t--){
    
        int con[N];
        int n;
        for(int i=0; i<N; i++){
            cin >> con[i];
        }
        cin >> n;
        
        if(n < 5){
            cout << n-1;
            continue;
        }

        int mat[N][N], mul[N][N];
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                mat[i][j] = (i == j)? 1: 0;
                if(i == 0){
                    mul[i][j] = con[j]%mod;
                }
                else{
                    mul[i][j] = (i == j+1)? 1: 0;
                }
            }
        }
        
        
        pwr(mat, mul, n-4);
        
        int ini[N][1]={{3}, {2}, {1}, {0}, {1}}, ans[N][1];

        for(int i=0; i<N; i++){
            for(int j=0; j<1; j++){
                ans[i][j] = 0;
                for(int k=0; k<N; k++){
                    ans[i][j] += (mat[i][k] * ini[k][j])%mod;
                    ans[i][j] %= mod;
                }
            }
        }

        cout << ans[0][0] << endl;
    }
    return 0;
}