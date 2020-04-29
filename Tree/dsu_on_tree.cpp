//Keeping hash for all the subtrees in nlogn

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


vector<vector<ll> > G;
ll n,col[100001],sz[100001],ans[100001];
vector<ll> cnt(100001,0);
void input(ll n){							//Input tree
	G.clear(); G.resize(n+1);
	ll u, v;
	for(ll i=1;i<=n-1;i++){
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
}

ll getSz(ll u, ll p){						//stores size of subtree
	ll csz=1;
	for(ll v:G[u]){
		if (v == p) continue;
		csz+=getSz(v, u);
	}
	return sz[u]=csz;
}

void add(ll u,ll p,ll bigC){				// Add contribution from all small child subtrees
	cnt[col[u]]++;
	for(ll v:G[u]){
		if(v==p || v==bigC) continue;
		add(v,u,bigC);
	}
}
void sub(ll u,ll p){						//Remove contribution of current subtree
	cnt[col[u]]--;
	for(ll v:G[u]){
		if(v==p) continue;
		sub(v,u);
	}
}
void dfs(ll u, ll p,bool keep){				//DSU on trees
	ll mx=-1,bigC=-1;
	for(ll v:G[u]){
		if (v == p) continue;
		if(sz[v]>mx){
			mx=sz[v]; bigC=v;
		}
	}
	for(ll v:G[u]){
		if(v==p || v==bigC) continue;
		dfs(v,u,0);
	}
	if(bigC !=-1){
		dfs(bigC,u,1);
	}
	add(u,p,bigC);
						//Write here
	
	if(!keep){
		sub(u,p);
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	#endif
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>col[i];
	input(n);
	getSz(1,0);
	dfs(1,0,1);
	for(ll i=1;i<=n;i++) cout<<ans[i]<<" ";
	return 0;
}