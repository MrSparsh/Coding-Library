// Segment Tree (Lazy) with range updates and range sum
#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct node{
	ll l,r,lazy,sum;
};

node tree[4*100000];

void pushup(ll k){
	tree[k].sum=tree[k*2].sum+tree[k*2+1].sum;
}
void pushdown(ll k){
	tree[k].sum+=(tree[k].r-tree[k].l+1)*tree[k].lazy;
	if(tree[k].l!=tree[k].r){
		tree[2*k].lazy+=tree[k].lazy;
		tree[2*k+1].lazy+=tree[k].lazy;
	}
	tree[k].lazy=0;
}

void build(ll l,ll r,ll k,ll arr[]){				//  k is used for tree node indexing (1 indexed)
	tree[k].l=l;
	tree[k].r=r;
	tree[k].lazy=0;
	if(l==r){
		tree[k].sum=arr[l];
		return;
	}
	ll mid=(l+r)/2;
	build(l,mid,k*2,arr);
	build(mid+1,r,k*2+1,arr);
	pushup(k);
}


void update(ll x,ll y,ll val,ll k){
	pushdown(k);
	if(tree[k].l>=x && tree[k].r<=y){
		tree[k].sum+=(tree[k].r-tree[k].l+1)*val;
		if(tree[k].l!=tree[k].r){
			tree[2*k].lazy+=val;
			tree[2*k+1].lazy+=val;
		}
	}else if(tree[k].r<x || tree[k].l>y){
		return;
	}else{
		update(x,y,val,k*2);
		update(x,y,val,k*2+1);
		pushup(k);
	}
}


ll query(ll x,ll y,ll k){
	pushdown(k);
	if(tree[k].l>=x && tree[k].r<=y){
		return tree[k].sum;
	}else if(tree[k].r<x || tree[k].l>y){
		return 0;
	}
	return query(x,y,2*k)+query(x,y,2*k+1);
}


void print(ll k){										//Print tree in preorder
	cout<<"("<<tree[k].sum<<","<<tree[k].lazy<<")  ";
	if(tree[k].l==tree[k].r){
		return;
	}
	print(2*k);
	print(2*k+1);
}

int main(){
	ll n=6;
	ll arr[6] = {1, 3, 5, 7, 9, 11};
	build(0,n-1,1,arr);
	cout<<query(1,3,1)<<endl;
	update(3,4,10,1);
	cout<<query(1,3,1)<<endl;
}