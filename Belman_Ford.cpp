#include<bits/stdc++.h>
#define ll long long
#define ppll pair<ll,pair<ll,ll> > 
using namespace std;

class Graph{
    ll V;
    vector<ppll> edges;
    vector<ll> dist,par;
    public:
    Graph(ll v){
        V=v;
        dist.resize(V+1,INT_MAX);
        par.resize(V+1,-1);
    }
    void addEdge(ll u,ll v,ll w){
        edges.push_back({w,{u,v}});
    }
    bool belman_ford(ll src){
        dist[src]=0;
        for(ll i=0;i<V-1;i++){
            for(auto edge:edges){
                ll w=edge.first;
                ll u=edge.second.first;
                ll v=edge.second.second;
                if(dist[u]!=INT_MAX && dist[u]+w<dist[v]){
                    dist[v]=dist[u]+w;
                    par[v]=u;
                }
            }
        }
        for(auto edge:edges){
            ll w=edge.first;
            ll u=edge.second.first;
            ll v=edge.second.second;
            if(dist[u]!=INT_MAX && dist[u]+w<dist[v]){
                return true;
            }
        }
        return false;
    }
    void printPath(ll des){
        vector<ll> path;
        ll curr=des;
        while(curr!=-1){
            path.push_back(curr);
            curr=par[curr];
        }
        reverse(path.begin(),path.end());
        for(ll node:path){
            cout<<node<<"->";
        }
        cout<<"\tDistance= "<<dist[des]<<endl;
    }
};

int main(){ 
    Graph g(5);
    g.addEdge(0,1,-1);
    g.addEdge(0,2,4);
    g.addEdge(1,2,3);
    g.addEdge(1,3,2);
    g.addEdge(1,4,2);
    g.addEdge(3,2,5);
    g.addEdge(3,1,1);
    g.addEdge(4,3,-3);
    if(g.belman_ford(0)){
        cout<<"Negative Cycle"<<endl;
    }
    for(int des=0;des<5;des++){
        g.printPath(des);
    }
    return 0;
}