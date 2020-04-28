// Finding Topologically sorted order using dfs and stack
#include <bits/stdc++.h>
using namespace std;
#define ll long long
	
vector<vector<ll> > G;  
vector<ll> vis;

ll n,m;
void dfs(ll u,stack<ll> &topo_order) {
	vis[u] = 1;
	for(ll v: G[u]) {
		if(!vis[v]) {
			dfs(v,topo_order);
		}
	}
	topo_order.push(u);
}
void topo_sort(stack<ll> &topo_order){
	vis.resize(n+1,0);
	for(ll i=1;i<=n;i++) {		
		if(!vis[i]) {
			dfs(i,topo_order);
		}
	}
}
	
int main() {
	cin>>n>>m;
	G.clear(); G.resize(n+1);
	for(ll i=0;i<m;i++) {
		ll u, v;
		cin>>u>>v;
		G[u].push_back(v);
	}
	cout<<"Topological Sort: \n";
	stack<ll> topo_order;
	topo_sort(topo_order);
	while(!topo_order.empty()) {
		cout<<topo_order.top()<<" ";
		topo_order.pop();
	}
	cout<<endl;
	return 0;
}