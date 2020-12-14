#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    string str;
	    cin >> str;

	    int n = str.size();
	    int dp[n][n];

	    int max_length = 1;
	    int start = 0;
	    int end = 0;

        // dpstate ->
        // dp[i][j] is 1 if str1[i...j] is a palindrome else 0.

	    for(int i=n-1;i>=0;i--){
	        for(int j=0;j<n;j++){

                // single character are always palindrome
                // base case (odd)
	            if(i==j)dp[i][j]=1;

                // dual character needs to be
                // both same for being palindrome
                // also a base case (even)
	            else if(i<n-1 && j==i+1 && str[i]==str[j]){
	                dp[i][j]=1;
	                max_length = 2;
	                start = i;
	                end = j;
	            }

                // initialise
	            else dp[i][j]=0; // other
	        }
	    }

	    for(int k=3;k<=n;k++){ // for every length
    	    for(int i=n+1-k;i>=0;i--){ // check the set of i's
    	        int j = i+k-1; // corresponding set of j's

                // if the str[i+1..j-1] is already a palindrome, check is str[i] == str[j]
    	        if(dp[i+1][j-1] && str[i]==str[j]){
    	            dp[i][j]=1;
    	            max_length = k;
    	            start = i;
    	            end = j;
    	        }
    	    }

	    }

	    cout << str.substr(start, max_length) << endl;
	}
	return 0;
}