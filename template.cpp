#include<bits/stdc++.h>
using namespace std;

// data types
#define ll long long int
#define ld long double

//funtion macros


// stl
#define lp(var,start,end) for (ll var = start; var <=end ; ++var)
#define ilp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
#define pf push_front
#define ff first
#define ss second
#define vll vector<ll>
#define vld vector<ld>
#define pll pair<ll,ll> 
#define pld pair<ld,ld> 
#define vpll vector<pll>
#define vpld vector<pld>
#define all(X) X.begin(),X.end()
#define sz(x) ((ll)((x).size()))

#define mod 1000000007

// utility functions
ll max(ll a, ll b){
    if(a>b)return a;
    return b;
}

ll min(ll a, ll b){
	if(a<b)return a;
    return b;
}

ll power(ll x, ll y, ll m=mod){
	if(y<0){
		x = power(x,m-2);
		y = -y;
	}
	ll ans=1;
	x = x % m;
	while(y){
		if(y&1) ans = (ans*x)%m;
		y=y/2;
		x=(x*x)%m;
	}
	return ans;
}

ll factorial(ll n, ll m=mod){
    ll ans = 1;
	ll i = 1;
    while(i<=n){
        ans = (ans*i)%m;
        i++;
    }
    return ans;
}

///////////////////////////////////////////////////////////

int main(){
    ios_base::sync_with_stdio(false);

	return 0;
}
