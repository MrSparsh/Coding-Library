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