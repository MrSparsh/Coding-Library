#include <bits/stdc++.h>
using namespace std;
#define loop(i, k, n) for (ll i = k; i < n; i += 1)
#define loop2(i, k, n, diff) for (ll i = k; i < n; i += diff)
#define debug2(x, y) cout << #x << " :: " << x << "\t" << #y << " :: " << y << endl;
#define debug3(x, y, z) cout << #x << " :: " << x << "\t" << #y << " :: " << y << "\t" << #z << " :: " << z << endl;
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
typedef long long ll; typedef pair<ll, ll> pl; typedef vector<ll> vl; typedef vector<pl> vpl; typedef vector<vl> vvl; typedef vector<vpl> vvpl;
const ll mod = 1000000007;

vvl G;
vl vis;
ll n,m;

void inputGraph(ll n, ll m){
	G.clear(); G.resize(n+1);
	ll i, u, v;
	loop(i,0,m-1){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
}

void dfs(ll u){
	for(ll v:G[u]){
		if (!vis[v]) continue;
		dfs(v);
	}
}

void bfs(ll st){
    vis.clear(); vis.resize(n+1,0);
    queue<ll> q;
    q.push(st);
    vis[st]=1;
    while(!q.empty()){
        ll u=q.front();q.pop();
        for(ll v:G[u]){
            if(!vis[v]){
                q.push(v);
                vis[v]=1;
            }
        }
    }
}

int main() {
	boost;
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	#endif

	
    return 0;
}