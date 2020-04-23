struct node{
		ll l,r,lazy,sum;
};
class Seg{
  public:
	vector<node> tree;

  Seg(ll n){
    tree.resize(4*n+1);
    build(0,n-1,1);
  }

	inline void pushup(ll k){
		tree[k].sum=tree[k*2].sum+tree[k*2+1].sum;
	}
	inline void pushdown(ll k){
    tree[k].sum+=(tree[k].r-tree[k].l+1)*tree[k].lazy;
		if(tree[k].l!=tree[k].r){
			tree[2*k].lazy+=tree[k].lazy;
			tree[2*k+1].lazy+=tree[k].lazy;
    }
		tree[k].lazy=0;
	}

	void build(ll l,ll r,ll k){
		tree[k].l=l;
		tree[k].r=r;
		tree[k].lazy=0;
		if(l==r){
			tree[k].sum=0;
			return;
		}
		ll mid=(l+r)/2;
		build(l,mid,k*2);
		build(mid+1,r,k*2+1);
		pushup(k);
	}


	void updateHelper(ll x,ll y,ll val,ll k){
		pushdown(k);
    if(tree[k].l>=x && tree[k].r<=y){
			tree[k].sum+=(tree[k].r-tree[k].l+1)*val;
      if(tree[k].l!=tree[k].r){
  			tree[2*k].lazy+=val;
  			tree[2*k+1].lazy+=val;
      }
			return;
		}else if(tree[k].r<x || tree[k].l>y){
      return;
    }else{
  		updateHelper(x,y,val,k*2);
  		updateHelper(x,y,val,k*2+1);
  		pushup(k);
    }
	}
	void update(ll x,ll y,ll val){
    updateHelper(x,y,val,1);
	}


	ll queryHelper(ll x,ll y,ll k){
		pushdown(k);
		if(tree[k].l>=x && tree[k].r<=y){
				return tree[k].sum;
			}else if(tree[k].r<x || tree[k].l>y){
		return 0;
		}
		return queryHelper(x,y,2*k)+queryHelper(x,y,2*k+1);
	}
	ll query(ll x,ll y){
		return queryHelper(x,y,1);
	}


	void printHelper(ll k){
		cout<<"("<<tree[k].sum<<","<<tree[k].lazy<<")  ";
		if(tree[k].l==tree[k].r){
		return;
		}
		printHelper(2*k);
		printHelper(2*k+1);
	}
	void print(){
		printHelper(1);
	}
};
