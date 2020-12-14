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
ll arr[1000000];
ll f(ll mid){
    return arr[mid];
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n;
    cin >> n;
    for(ll i=0;i<n;i++){
        cin >> arr[i];
    }
    ll r = n-1;
    ll l = 0;
    ll eps = 3;
    while(r-l>3){
        ll mid1 = l+(r-l)/3;
        ll mid2 = r-(r-l)/3;
        if(f(mid1)<f(mid2)){
            r = mid2;
        }
        else{
            l = mid1;
        }
    }
    ll ans = LLONG_MAX;
    for(ll i=l;i<=r;i++){
        ans =min(ans,f(i));
    }
    cout << ans << endl;

	return 0;
}
