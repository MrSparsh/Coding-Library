//Kruskal algo to find MST

#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll p[100001];
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

void init(){
    for(int i=1;i<=n;i++) p[i]=i;
}
ll find(ll x){
    if(x!=p[x]) return p[x]=find(p[x]);
    else return x;
}
bool Union(ll x,ll y){
    ll px=p[x];
    ll py=p[y];
    if(px!=py){
        p[px]=py;
        return true;
    }
    return false;
}

ll kruskal(){
    sort(edges.begin()+1,edges.end());      //1-indexed
    ll ans=0;
    init();
    for(ll i=1;i<=m;i++){
        ll w=edges[i].first;
        ll u=edges[i].second.first;
        ll v=edges[i].second.second;
        if(Union(u,v)){
            ans+=w;
        }
    }
    return ans;
}
int main(){
    cin>>n>>m;
    inputGraph();
    cout<<kruskal();
    return 0;
}