// Merge Sort Tree to return count of numbers<=x from (l,r)
#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<ll> > tree(4*300001+1);
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

void printTree(ll l,ll r,ll k){
	cout<<"("<<l<<","<<r<<")-> ";
	for(ll i=0;i<tree[k].size();i++) cout<<tree[k][i]<<" ";
	cout<<endl;
	if(l==r) return;
	ll m=(l+r)/2;
	printTree(l,m,2*k);
	printTree(m+1,r,2*k+1);
}

int main(){
	a[0]=4,a[1]=3,a[2]=6,a[3]=5,a[4]=9;		//[4,3,6,5,9]
	build(0,4,1);		
	cout<<query(0,4,8,0,4,1);				//count of numbers <= 9 from 0 to 4
	return 0;
}