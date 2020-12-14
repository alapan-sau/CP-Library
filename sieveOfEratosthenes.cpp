#include<bits/stdc++.h>
using namespace std;

#define ll long long int

bool prime[10000000];

void sieveOfEratosthenes(ll n){

    for(ll i=0;i<=n;i++) prime[i]=true;
    for(ll p=2;p*p<=n;p++){
        if(prime[p]){
            for(ll c=p*p;c<=n;c+=p){
                prime[c]=false;
            }
        }
    }
    ll cnt=0;
    for(ll p=2;p<=n;p++){
        if(prime[p]) {
            cout << p << " ";
            cnt++;
        }
    }
    cout << endl;
    cout << cnt << endl;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n;
    cin >> n;
    sieveOfEratosthenes(n);
	return 0;
}
