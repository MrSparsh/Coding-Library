//Dijikstra algo to find shortest distance from src to all nodes

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
	}
}

ll dis[100001];
void dijikstra(ll src){
	for(int i=1;i<=n;i++){
		dis[i]=1e18;
	}
	dis[src]=0;
	set<pair<ll,ll>> st;
	st.insert({dis[src],src});
	while(!st.empty()){
		auto fr= *st.begin();
		st.erase(st.begin());
		ll u=fr.second;
		for(auto p:G[u]){
			ll v=p.second;
			ll w=p.first;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				st.insert({dis[v],v});
			}
		}
	}
}


int main() {
	cin>>n>>m;
	inputGraph();
	ll src,des; cin>>src>>des;
	dijikstra(src);
	if(dis[des]==1e18){
		cout<<"NO"<<endl;
	}else{
		cout<<dis[des]<<endl;
	}
    return 0;
}