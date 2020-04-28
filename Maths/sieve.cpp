// Prime Factorization in nlogn
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll minP[1000001];                           //minP[x] stores min prime factor of x
void sieve(ll n) {
    
    for(ll i=2; i<=n; i++) {
        minP[i] = i;
    }
    
    for(ll i=2; i*i<=n; i++) {
        if(minP[i] == i) {
            for(ll j=i*i; j<=n; j+=i) {
                minP[j] = min(minP[j],i);
            }
        }
    }
}
     
void factorize(ll n) {              // To get the prime factorisation in logn
    ll sp = minP[n];
    while(n > 1) {
        ll sp = minP[n];
        ll cnt = 0;
        while(n%sp == 0) {
            n /= sp;
            cnt++;
        }
        cout<<sp<<"^"<<cnt<<" ";
    }
}

int main(){
    sieve(1000000);
    factorize(12);
}