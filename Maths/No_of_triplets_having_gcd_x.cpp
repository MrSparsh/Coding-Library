#include <bits/stdc++.h>   
#define mod 1000000007
#define pll pair<ll,ll> 
#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rep(i,l,r) for(ll i=l;i<=r;i++)
using namespace std;
typedef long long ll;
ll power(ll x, ll y) { ll res=1; x=x%mod; while(y>0){if(y & 1){res=(res*x)%mod;} y=y>>1; x=(x*x)%mod;} return res; }
ll inv(ll x){return power(x,mod-2);}

//Find the no of tripets having GCD as x
ll n,arr[100001],mp[1000001],trip[1000001],mul[1000001];
int main() {
    boost;
    freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        mp[arr[i]]++;
    } 
    for(int i=1;i<=1000000;i++){
        for(int j=i;j<=1000000;j+=i){
            mul[i]+=mp[j];
        }
    }
    for(int i=1;i<=1000000;i++){
        trip[i]=mul[i]*(mul[i]-1)*(mul[i]-2)/6;
    }  
    for(ll i=1000000;i>=1;i--){
        for(ll j=2*i;j<=1000000;j+=i){
            trip[i]-=trip[j];
        }
    }
    cout<<trip[1];
    return 0;
}
