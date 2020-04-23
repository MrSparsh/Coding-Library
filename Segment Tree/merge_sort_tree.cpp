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
	loop(i,0,tree[k].size()) cout<<tree[k][i]<<" ";
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