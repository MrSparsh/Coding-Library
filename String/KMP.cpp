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

ll lcps[100001];
void createLCPS(string &key){
    ll n=key.length();
    lcps[0]=0;
    for(ll j=1;j<n;j++){
        ll i=lcps[j-1];
        while(i>0 && key[i]!=key[j]){
            i=lcps[i-1];
        }
        if(key[i]==key[j]){
            lcps[j]=i+1;
        }else{
            lcps[j]=0;
        }
    }
    lcps[n]=0;
}

ll countOcc(string &txt,string &key){
    ll n=txt.length(),len=key.length(),cnt=0;
    ll pos=0;
    for(ll i=0;i<n;i++){
        while(pos>0 && txt[i]!=key[pos]){
            pos=lcps[pos-1];
        }
        if(txt[i]==key[pos]){
            pos++;
        }
        if(pos==len){
            cnt++;
        }
    }
    return cnt;
}
int main() {
    boost;
    string txt,key;
    cin>>txt>>key;
    createLCPS(key);
    ll occ = countOcc(txt,key);
    cout<<occ;
}
