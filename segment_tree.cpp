struct Node{
    long long l,r,val;
};
struct SegmentTree{
    long long n;
    long long def_val=0; //Can Change
    vector<Node> tree;
    long long op(long long a,long long b){
        return a+b; 
    }
    void pushup(long long x){
        tree[x].val=op(tree[x*2].val,tree[x*2+1].val);
    }
    void build(long long curr,long long l,long long r){
        tree[curr].l=l;
        tree[curr].r=r;
        if(l==r){
            tree[curr].val=def_val;
            return;
        }
        long long mid=(l+r)/2;
        build(2*curr,l,mid);
        build(2*curr+1,mid+1,r);
        pushup(curr);
    }
    SegmentTree(long long n){
        this->n=n;
        tree.resize(4*(n+1));
        build(1,1,n);
    }
    void update(long long idx,long long val){
        updateHelper(1,idx,val);
    }
    void updateHelper(long long curr,long long idx,long long val){
        long long l=tree[curr].l;
        long long r=tree[curr].r;
        if(l==r){
            tree[curr].val=val;
            return;
        }
        long long mid=(l+r)/2;
        if(idx<=mid){
            updateHelper(curr*2,idx,val);
        }else{
            updateHelper(curr*2+1,idx,val);
        }
        pushup(curr);
    }
    long long query(long long ql,long long qr){
        return queryHelper(1,ql,qr);
    }
    long long queryHelper(long long curr,long long ql,long long qr){
        long long l=tree[curr].l;
        long long r=tree[curr].r;
        if(ql<=l && qr>=r){
            return tree[curr].val;
        }else if(l>qr && r<ql){
            return def_val;
        }
        long long ans=def_val;   
        long long mid=(l+r)/2;
        if(ql<=mid){
            ans=op(ans,queryHelper(2*curr,ql,qr));
        }
        if(qr>mid){
            ans=op(ans,queryHelper(2*curr+1,ql,qr));
        }
        return ans;
    }
};
