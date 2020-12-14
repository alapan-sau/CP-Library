#include<bits/stdc++.h>

using namespace std;

int lcs(string str1, string str2){

    int len1 = str1.size();
    int len2 = str2.size();

    int dp[len1+1][len2+1];

    for(int i=0;i<=len1;i++){
        for(int j=0;j<=len2;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
            else if(str1[i-1] == str2[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[len1][len2];
}


int main(){

    string str1="alapan";
    string str2="alapan";

    cout << lcs(str1, str2) << endl;
    return 0;
}