#include <bits/stdc++.h>
using namespace std;


// The most classic DP problem

int dp[1000][1000];

// returns the maximum value sum
int ks(int maxWeight, int wt[], int val[], int n){

    if(dp[n][maxWeight]!=-1) return dp[n][maxWeight];

    // final value to be updated in table
    int ans = 0;

    // base case with no items or no capacity
    if(n==0 || wt==0 ) ans = 0;

    // if the current(latest) item alone
    // has more weight than the whole knapsack capacity,
    // just ditch it
    else if(wt[n-1] > maxWeight){
        ans = ks(maxWeight,wt,val,n-1);
    }

    // check keeping the current item
    // is better or not?
    else{
        ans = max(ks(maxWeight,wt,val,n-1) /* dont take */, ks(maxWeight-wt[n-1],wt,val,n-1)+val[n-1] /* take */);
    }

    dp[n][maxWeight] = ans;
    return dp[n][maxWeight];
}


// iterative way
int ks1(int maxWeight, int wt[], int val[], int n){

    // dpstate ->
    // dp1[i][j] is the highest value sum when capacity is j and only items till ith one is considered

    int dp1[n+1][maxWeight+1]={0};

    for(int i=0;i<=n;i++){
        for(int j=0;j<=maxWeight;j++){
            if(i==0 || j==0) dp1[i][j]=0;
            else if(wt[i-1] > j) dp1[i][j] = dp1[i-1][j];
            else{
                dp1[i][j] = max(dp1[i-1][j], val[i-1] + dp1[i-1][j-wt[i-1]]);
            }
        }
    }
    return dp1[n][maxWeight];
}


int main(){
    int val[] = { 1, 2, 3 };
    int wt[] = { 4, 5, 1};
    int W = 4;
    int n = sizeof(val) / sizeof(val[0]);

    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            dp[i][j]=-1;
        }
    }

    cout << ks(W, wt, val, n) << endl;
    cout << ks1(W, wt, val, n) << endl;

    // should print 50;
    return 0;
}
