
#include<bits/stdc++.h>
using namespace std;

/*
z algorithm function for matching suffix to prefix of the string s.

It basically calculate max length of the substring starting with 
the current index which matches the prefix of the whole string.

It is done for all the indexes of the string.

If n -> length of string then,
its time complexity is O(n), since it uses the values calculated 
for the previous indexes of the string. Its space complexity is O(n), 
as we have used z-array to store values. 
*/
vector<int> z_algorithm(string s){
    
    int n = s.length();

    // below vector is z array which stores the values of the matching suffix.
    vector<int> z(n);

    int l = 0, r = 0;
    for(int i=1; i<n; i++){

        // if i>r, then there is no substring starting before this i, which ends 
        // after this i. Therefore there is no use of previous values of z.
        if(i > r){
            l = i;
            r = i-1;
            // Doing comparisons and increasing z[i] value if charcters matched.
            while(r+1 < n && s[r+1] == s[r-i+1]){
                z[i]++, r++;
            }
        }
        
        // If i<r, then it means we are inside z-box[l, r]. Therefore
        // we need to copy corresponding z values calculated before
        // to the indexes in the z-box.
        else{ 
            
            // check finds if the match goes outside the z-box.
            int check = z[i-l] + i;
            
            // For now we are assigning z[i] value such that it does not
            // go outside the z-box. We will increase it further after
            // comparisons in the if clause.
            z[i] = min(z[i-l], r-i+1);
            
            // If check goes outside the z-box then we do further comparisons.
            if(check > r){
                int ind = min(z[i-l], r-i+1);
                l = i;
                
                // Doing comparisons and increasing z[i] value if characters matched.
                while(s[r+1] == s[ind] && r < n){
                    r++, z[i]++, ind++;
                }
            }
        }
    }
    return z;
}
 