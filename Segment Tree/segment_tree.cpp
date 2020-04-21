#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define loop(i,k,n) for(ll i=k;k<n?i<=n:i>=n;k<n?i+=1:i-=1)
#define loop2(i,k,n,diff) for(ll i=k;k<n?i<=n:i>=n;k<n?i+=diff:i-=diff)
#define ll long long
#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define mp make_pair
#define PI 3.1415926535897932384626
typedef pair<ll, ll>	pl;
typedef vector<ll>		vl;
typedef vector<pl>		vpl;
typedef vector<vl>		vvl;
const ll mod = 1000000007;

class Seg{
  public:
	vector<ll> tree;
	ll n;

  Seg(ll n,ll arr[]){
    tree.resize(4*n+1);
	this->n=n;
    build(0,n-1,1,arr);
  }

	inline void pushup(ll k){
		tree[k]=tree[k*2]+tree[k*2+1];
	}

	void build(ll l,ll r,ll k,ll arr[]){
		if(l==r){
			tree[k]=arr[l];
			return;
		}
		ll mid=(l+r)/2;
		build(l,mid,k*2,arr);
		build(mid+1,r,k*2+1,arr);
		pushup(k);
	}


	void updateHelper(ll idx,ll val,ll l,ll r,ll k){
		if(l==r){
			tree[k]=val;
			return;
		}
		ll m=(l+r)/2;
		if(idx<=m){
			updateHelper(idx,val,l,m,2*k);
		}else{
			updateHelper(idx,val,m+1,r,2*k+1);
		}
		pushup(k);
	}
	void update(ll idx,ll val){
    	updateHelper(idx,val,0,n-1,1);
	}


	ll queryHelper(ll ql,ll qr,ll l,ll r,ll k){
		if(l>=ql && r<=qr){
			return tree[k];
		}else if(l>qr || r<ql){
			return 0;
		}
		ll m=(l+r)/2;
		return queryHelper(ql,qr,l,m,2*k)+queryHelper(ql,qr,m+1,r,2*k+1);
	}
	ll query(ll ql,ll qr){
		return queryHelper(ql,qr,0,n-1,1);
	}

    void print(){
		loop(k,1,4*n){
			cout<<tree[k]<<" ";
		}
		cout<<endl;
	}
};

int main() {
    boost;
	ll arr[]={1,3,5,7,9,11};
    Seg tree(6,arr);
	tree.print();
	cout<<tree.query(1,3)<<endl;
	tree.update(3,9);
	tree.print();
	return 0;
}