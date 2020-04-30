//Prims algo to find MST

#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<pair<ll,ll>>> G;
ll n,m;

void inputGraph(){
	G.clear(); G.resize(n+1);
	ll i, u, v, w;
	for(i=1;i<=m;i++){
		cin>>u>>v>>w;
		G[u].push_back({w,v});
        G[v].push_back({w,u});
	}
}

ll prims(ll src){
    vector<ll> vis(n+1,0);
    ll ans=0;
	set<pair<ll,ll>> st;
	st.insert({0,src});
	while(!st.empty()){
		auto fr= *st.begin();
		st.erase(st.begin());
        ll w=fr.first;
		ll u=fr.second;
        if(vis[u]) continue;
        else vis[u]=true;
        ans+=w;
		for(auto p:G[u]){
			ll v=p.second;
			ll cw=p.first;
			if(!vis[v]){
				st.insert({cw,v});
			}
		}
	}
    return ans;
}


int main() {
	cin>>n>>m;
	inputGraph();
	cout<<prims(1)<<endl;
    return 0;
}