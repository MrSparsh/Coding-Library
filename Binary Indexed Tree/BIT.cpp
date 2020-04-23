ll BIT[100001],n;
void update(ll idx,ll val){
    idx++;
    while(idx<=n){
        BIT[idx]+=val;
        idx=idx+(idx&(-idx));
    }
}
ll query(ll idx){
    idx++;
    ll ans=0;
    while(idx>0){
        ans+=BIT[idx];
        idx=idx-(idx&(-idx));
    }
    return ans;
}
void printBIT(){
    loop(i,1,n+1) cout<<BIT[i]<<" ";
    cout<<endl;
}
