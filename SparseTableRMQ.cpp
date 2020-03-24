#include <bits/stdc++.h>
#define mod 1000000007
#define pll pair<ll,ll>
typedef long long ll;
using namespace std;
#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define loop(x,l,n) for(ll x = l; x <= n; ++x)
ll power(ll x, ll y) { ll res=1; x=x%mod; while(y>0){if(y & 1){res=(res*x)%mod;} y=y>>1; x=(x*x)%mod;} return res; }
ll inv(ll x){return power(x,mod-2);}

ll n,sparse[200001][18];
void preprocess(ll a[]){
  for(int i=0;i<n;i++){sparse[i][0]=a[i];}
  for(int j=1;(1<<j)<=n;j++){
    for(int i=0;i+(1<<j)-1<n;i++){
      sparse[i][j]=max(sparse[i][j-1],sparse[i+(1<<(j-1))][j-1]);
    }
  }
}
ll query(ll l,ll r){
  int diff=log2(r-l+1);
  return max(sparse[l][diff],sparse[r-(1ll<<diff)+1ll][diff]);
}
void printTable(){
  for(int i=0;i<n;i++){
    for(int j=0;i+(1<<j)-1<n;j++){
      cout<<sparse[i][j]<<" ";
    }
    cout<<endl;
  }
}
int main(){
  ll arr[]={5,4,8,1,9,2,5,7,1,6,8};
  n=11;
  preprocess(arr);
  printTable();
  return 0;
}
