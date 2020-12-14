#include <bits/stdc++.h>

using namespace std;

// Problem name is edit Distance.

int modifyString(string s, string t){
    int sl = s.length();
    int tl = t.length();

    int dp[sl+1][tl+1];

    // dpstate->
    // dp[i][j] is the cost needed for converting s[0,..,i] to t[0,...j];

    for(int i=0;i<=sl;i++){
        for(int j=0;j<=tl;j++){

            // from empty to j characters(all insert);
            if(i==0){
                dp[i][j]=j;
            }

            // from i to empty(all delete);
            else if(j==0){
                dp[i][j]=i;
            }
            // if characters are same, cheers take till previous
            else if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }

            // if they are not same, either insert, or delete or just modify.
            else{
                int mini = min(dp[i][j-1],dp[i-1][j]); // insert or delete?
                mini = min(mini,dp[i-1][j-1]);      // or just modify?
                dp[i][j] = 1 + mini;
            }
        }
    }
    return dp[sl][tl];
}

int main(){
    string s = "apa";
    string t = "ala";

    cout << modifyString(s,t) << endl;
    return 0;
}