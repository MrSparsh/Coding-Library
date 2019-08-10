#include <bits/stdc++.h>   
typedef long long ll;
using namespace std;

ll n,depth[100001],len=18,anc[100001][18],q;
vector<vector<ll> > G;

void dfs(ll u,ll par){
    depth[u]=depth[par]+1;
    anc[u][0]=par;
    for(int i=1;i<len;i++){
        anc[u][i]=anc[anc[u][i-1]][i-1];
    }
    for(ll v:G[u]){
        if(v!=par){
            dfs(v,u);
        }
    }
}
ll lca(ll u,ll v){
    if(depth[u]>depth[v]){
        ll tmp=u;
        u=v;
        v=tmp;
    }
    for(ll i=len-1;i>=0;i--){
        if(depth[anc[v][i]]>=depth[u]){
            v=anc[v][i];
        }
    }
    if(u==v){
        return u;
    }
    for(ll i=len-1;i>=0;i--){
        if(anc[u][i]!=anc[v][i]){
            u=anc[u][i];
            v=anc[v][i];
        }
    }
    return anc[u][0];
}
int main() {
    cin>>n;
    G.clear(),G.resize(n+1);
    for(int i=0;i<n-1;i++){
        ll u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,0);
}
