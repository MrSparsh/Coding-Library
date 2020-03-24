#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
ll power(ll x, ll y) { ll res=1; x=x%mod; while(y>0){if(y & 1){res=(res*x)%mod;} y=y>>1; x=(x*x)%mod;} return res; }
ll inv(ll x){return power(x,mod-2);}

 
int main(){
    boost;
    
    return 0;
}