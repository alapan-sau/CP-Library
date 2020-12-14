#include<bits/stdc++.h>
using namespace std;

// data types
#define ll long long int
#define ld long double

double n;
bool f(double mid){
    if(mid < n) return false;
    return true;
}
int main(){
    scanf("%lf",&n);
    double l=0;
    double r=1000000;
    while(r-l>10e-12){
        double mid = l+(r-l)/2;
        if(f(mid)) r = mid;
        else l = mid;
    }
    printf("%lf\n",l);
	return 0;
}
