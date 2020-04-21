#include<bits/stdc++.h>
using namespace std;
#define loop(i,k,n) for(ll i=k;i<=n;i+=1)
#define loop2(i,k,n,diff) for(ll i=k;i<=n;i+=diff)
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
typedef long long ll; typedef pair<ll, ll> pl; typedef vector<ll> vl; 
typedef vector<pl> vpl; typedef vector<vl> vvl; typedef vector<vpl> vvpl;
const ll mod = 1000000007;


ll power(ll x, ll y) { 
	ll res=1; 
	x=x%mod; 
	while(y>0){
		if(y & 1){
			res=(res*x)%mod;
		}
		y=y>>1; 
		x=(x*x)%mod;
	} 
	return res; 
}

ll inv(ll x){
	return power(x,mod-2);
}

ll minP[1000001];
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
     
void factorize(ll n) {
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




int main() {
	boost;
    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	#endif
	sieve(1000000);
    factorize(12);
    
    return 0;
}