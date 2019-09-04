#include <bits/stdc++.h>   
#define mod 1000000007
#define pll pair<ll,ll> 
typedef long long ll;
using namespace std;
#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
ll power(ll x, ll y) { ll res=1; x=x%mod; while(y>0){if(y & 1){res=(res*x)%mod;} y=y>>1; x=(x*x)%mod;} return res; }
ll inv(ll x){return power(x,mod-2);}

int lis(vector<ll> &arr) {
   set<int> st;
   for(int i=0;i<arr.size();i++){
       auto it = st.upper_bound(arr[i]);
       if(it==st.end()){
           st.insert(arr[i]);
       }else{
           st.erase(it);
           st.insert(arr[i]);
       }
   }
   return st.size();
   
}

int main(){
    ll n;
    cin>>n;
    vector<ll> v{4,2,3,5,7,8,1,2};
    cout<<lis(v);
}