#include<bits/stdc++.h>
using namespace std;

// data types
#define ll long long int
#define ld long double

ll gcd(ll a, ll b){
    if(b==0) return a;
    else{
        return gcd(b,a%b);
    }
}
ll lcm(ll a,ll b){
    return (a*b)/gcd(a,b);
}
int main(){
    ios_base::sync_with_stdio(false);
    ll a,b;
    cin >> a >> b;
    cout << gcd(a,b) << " " << lcm(a,b) << endl;
	return 0;
}
