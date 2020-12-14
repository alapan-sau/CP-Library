#include<bits/stdc++.h>
using namespace std;

// data types
#define ll long long int
#define ld long double


bool arr[1000001];

bool f(ll mid){
    return arr[mid];
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n;
    cin >> n;
    for(ll i=0;i<=1000000;i++){
        if(i<=n) arr[i]=true;
        else arr[i]=false;
    }
    // array of the form {true, true, true, ..., true, false, false, ...,false}


    // finding first false:
    ll l=0;ll r=1000000;
    while(l<r){
        ll mid = l+(r-l)/2;
        if(f(mid)) l = mid+1;
        else r = mid;
    }
    if(f(l)==true) cout << "all values are true" << endl;
    else cout << l << endl;

    // finding last true
    l=0;r=1000000;
    while(l<r){
        ll mid = l+(r-l+1)/2;
        if(f(mid)) l = mid;
        else r = mid-1;
    }
    if(f(l)==false) cout << "all values are false" << endl;
    else cout << l << endl;

	return 0;
}
