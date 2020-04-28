// Segment Tree with point updates and range sum
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll tree[4*200001];
void pushup(ll k){
	tree[k]=tree[k*2]+tree[k*2+1];
}

void build(ll l,ll r,ll k,ll arr[]){						//  k is used for tree node indexing (1 indexed)
	if(l==r){
		tree[k]=arr[l];
		return;
	}
	ll mid=(l+r)/2;
	build(l,mid,k*2,arr);
	build(mid+1,r,k*2+1,arr);
	pushup(k);
}


void update(ll idx,ll val,ll l,ll r,ll k){
	if(l==r){
		tree[k]=val;
		return;
	}
	ll m=(l+r)/2;
	if(idx<=m){
		update(idx,val,l,m,2*k);
	}else{
		update(idx,val,m+1,r,2*k+1);
	}
	pushup(k);
}


ll query(ll ql,ll qr,ll l,ll r,ll k){
	if(l>=ql && r<=qr){
		return tree[k];
	}else if(l>qr || r<ql){
		return 0;
	}
	ll m=(l+r)/2;
	return query(ql,qr,l,m,2*k)+query(ql,qr,m+1,r,2*k+1);
}

int main(){
	ll n=6;
	ll arr[6] = {1, 3, 5, 7, 9, 11};
	build(0,n-1,1,arr);
	cout<<query(1,3,0,n-1,1)<<endl;
	update(1,10,0,n-1,1);
	cout<<query(1,3,0,n-1,1)<<endl;
}