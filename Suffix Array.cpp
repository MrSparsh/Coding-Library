#include <bits/stdc++.h>   
#define mod 1000000007
#define pll pair<ll,ll> 
#define pb push_back
typedef long long ll;
using namespace std;
#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
ll power(ll x, ll y) { ll res=1; x=x%mod; while(y>0){if(y & 1){res=(res*x)%mod;} y=y>>1; x=(x*x)%mod;} return res; }
ll inv(ll x){return power(x,mod-2);}
ll order[10][20],SA[20],lvl=0,n; 

void createSA(string str){
    ll cnt=2;
    n=str.length();
    for(ll i=0;i<n;i++){
        order[lvl][i]=str[i]-'a';
    }
    lvl=1;
    for(lvl=1,cnt=2;cnt<n;cnt*=2,lvl++){
        vector<vector<ll> > tmp(n,vector<ll>(3));
        for(ll j=0;j<n;j++){
            tmp[j][0]=order[lvl-1][j];
            tmp[j][1]=j+cnt/2<n ? order[lvl-1][j+cnt/2] : -1;
            tmp[j][2]=j;
        }
        sort(tmp.begin(),tmp.end());
        for(ll j=0;j<n;j++){
            order[lvl][tmp[j][2]] = (j>0 && tmp[j][0]==tmp[j-1][0] && tmp[j][1]==tmp[j-1][1]) ? order[lvl][tmp[j-1][2]] : j;
        }
    }
    lvl--;
    for(int i=0;i<n;i++){
        SA[order[lvl][i]]=i;
    }
}

ll LCP(ll sfx1,ll sfx2){
    ll ans=0;
    if(sfx1==sfx2){
        return n-sfx1;
    }
    for(ll i=lvl;i>=0;i--){
        if(order[i][sfx1]==order[i][sfx2]){
            ans+=(1<<i);
            sfx1+=(1<<i);
            sfx2+=(1<<i);
        }
    }
    return ans;
}

int main() {
    boost;
    string str = "banana";
    createSA(str);
    int n=str.length();
    for(ll i=0,cnt=1;cnt<n;cnt*=2,i++){
        for(ll j=0;j<n;j++){
            cout<<order[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(ll j=0;j<n;j++){
            cout<<SA[j]<<" ";
        }
    cout<<endl;
    cout<<LCP(1,1);
}
