//Floyd Warshall algo to find shortest distance from each node to every other node.

#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<pair<ll,pair<ll,ll>>> edges;
ll n,m;

void inputGraph(){
	ll i, u, v, w;
	edges.clear(); edges.resize(m+1);
	for(i=1;i<=m;i++){
		cin>>u>>v>>w;
		edges[i]={w,{u,v}};
	}
}

ll dis[101][101];
void floyd_warshall(){
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			if(i==j) dis[i][j]=0;
			else dis[i][j]=1e18;
		}
	}
	for(ll i=1;i<=m;i++){
		ll u=edges[i].second.first,v=edges[i].second.second;
		ll w=edges[i].first;
		dis[u][v]=min(dis[u][v],w);
		dis[v][u]=min(dis[v][u],w);
	}
    for(ll k = 1; k <= n; k++){
		for(ll i = 1; i <= n; i++){
			for(ll j = 1; j <= n; j++){
				dis[i][j] = min( dis[i][j], dis[i][k] + dis[k][j] );
			}
		}
	}
}
int main() {
	cin>>n>>m;
	inputGraph();
	ll src,des; cin>>src>>des;
	floyd_warshall();
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			cout<<dis[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
    return 0;
}