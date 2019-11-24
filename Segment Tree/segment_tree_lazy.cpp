struct node{
		ll l,r,lazy,sum;
};
struct Seg{
	node tree[100005*4];
	
	inline void pushup(ll k){
		tree[k].sum=tree[k*2].sum+tree[k*2+1].sum;
	}
	
	inline void pushdown(ll k){
		if(tree[k].lazy){
			tree[k*2].sum+=(tree[k*2].r-tree[k*2].l+1)*tree[k].lazy; 
			tree[k*2+1].sum+=(tree[k*2+1].r-tree[k*2+1].l+1)*tree[k].lazy;
			tree[k*2].lazy+=tree[k].lazy;
			tree[k*2+1].lazy+=tree[k].lazy;
			
			tree[k].lazy=0;
		}
	}
	
	void build(ll l,ll r,ll k){
		tree[k].l=l;
		tree[k].r=r;
		tree[k].lazy=0;
		if(l==r){
			tree[k].sum=0;
//			cin>>tree[k].sum;
			return;
		}
		ll mid=(l+r)/2;
		build(l,mid,k*2);
		build(mid+1,r,k*2+1);
		pushup(k); 
	}
	
	void update(ll l,ll r,ll val,ll k){
		if(l<=tree[k].l && r>=tree[k].r){
			tree[k].sum+=(tree[k].r-tree[k].l+1)*val;
			tree[k].lazy+=val;  
			return;
		}
		pushdown(k); 
		
		ll mid=(tree[k].l+tree[k].r)/2;
		if(l<=mid){
			update(l,r,val,k*2);
		}
		if(r>mid){
			update(l,r,val,k*2+1);
		}	
		
		pushup(k); 
	}
	
	ll query(ll l,ll r,ll k){
		if(l<=tree[k].l && r>=tree[k].r){
			return tree[k].sum;
		}
		
		pushdown(k);
		
		ll mid=(tree[k].l+tree[k].r)/2;
		ll ans=0;
		if(l<=mid){
			ans+=query(l,r,k*2); 
		}
		if(r>mid){
			ans+=query(l,r,k*2+1);
		}
		
		return ans;
	} 
};
