#include<bits/stdc++.h>
using namespace std;

int equalPartition(int N, int arr[]){
    int sum;
    int n = N;
    for(int i=0;i<n;i++){
        sum +=arr[i];
    }
    
    if(sum%2 != 0) return 0;

    int dp[n+1][sum/2 + 1];

    for(int i=0; i<=n; i++){
        for(int j=0; j<=sum/2; j++){
            if(j==0) dp[i][j]=1;
            else if(i==0) dp[i][j]=0;
            else if(j>=arr[i-1]){
                dp[i][j] = max(dp[i-1][j] , dp[i-1][j-arr[i-1]]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
            // cout << dp[i][j] << " ";
        }
        // cout << endl;
    }
    return dp[n][sum/2];
}

int main(){
    int arr[] = {1,5,11,5};
    int N = sizeof(arr)/sizeof(arr[0]);

    cout << equalPartition(N,arr) << endl;
}