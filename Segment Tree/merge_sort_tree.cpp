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

vvl tree(4*300001+1);
ll a[300001],n;
void merge(ll k){
	ll i=0,j=0;
	while(i<tree[2*k].size() && j<tree[2*k+1].size()){
		if(tree[2*k][i]<tree[2*k+1][j]) tree[k].push_back(tree[2*k][i++]);
		else tree[k].push_back(tree[2*k+1][j++]);
	}
	while(i<tree[2*k].size()){
		tree[k].push_back(tree[2*k][i++]);
	}
	while(j<tree[2*k+1].size()){
		tree[k].push_back(tree[2*k+1][j++]);
	}
}
void build(ll l,ll r,ll k){
	if(l==r){
		tree[k].push_back(a[l]);
		return;
	}
	ll m=(l+r)/2;
	build(l,m,2*k);
	build(m+1,r,2*k+1);
	merge(k);
}

void printTree(ll l,ll r,ll k){
	cout<<"("<<l<<","<<r<<")-> ";
	loop(i,0,(int)tree[k].size()-1) cout<<tree[k][i]<<" ";
	cout<<endl;
	if(l==r) return;
	ll m=(l+r)/2;
	printTree(l,m,2*k);
	printTree(m+1,r,2*k+1);
}

ll query(ll ql,ll qr,ll x,ll l,ll r,ll k){
	if(l>qr || r<ql){
		return 0;
	}else if(l>=ql && r<=qr){
		ll ub=upper_bound(tree[k].begin(),tree[k].end(),x)-tree[k].begin();
		return ub;
	}
	ll m=(l+r)/2;
	return (query(ql,qr,x,l,m,2*k)+query(ql,qr,x,m+1,r,2*k+1));
}

int main() {
	boost;
    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	#endif
    n=5;
	a[0]=2,a[1]=1,a[2]=5,a[3]=4,a[4]=3;
    build(0,n-1,1);
    printTree(0,n-1,1);
    cout<<query(0,3,4,0,n-1,1);
    return 0;
}