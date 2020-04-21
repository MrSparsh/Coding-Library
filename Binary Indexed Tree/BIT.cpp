#include <bits/stdc++.h>
#define mod 1000000007
#define pll pair<ll,ll>
typedef long long ll;
using namespace std;
#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

ll BIT[100001],n;
void update(ll idx,ll val){
    idx++;
    while(idx<=n){
        BIT[idx]+=val;
        idx=idx+(idx&(-idx));
    }
}
ll query(ll idx){
    idx++;
    ll ans=0;
    while(idx>0){
        ans+=BIT[idx];
        idx=idx-(idx&(-idx));
    }
    return ans;
}
int main() {
    boost;
    n=12;
    ll arr[]={2,1,1,3,2,3,4,5,6,7,8,9};
    for(ll i=0;i<n;i++){
        update(i,arr[i]);
    }
    for(ll i=0;i<=n;i++){
        cout<<BIT[i]<<" ";
    }
}
