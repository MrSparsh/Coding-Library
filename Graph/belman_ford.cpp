// Belman Ford algorithm to compute shortest distance from source when graph contains negative weights.
#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll n;
vector<pair<ll,pair<ll,ll>>> edges;
vector<ll> dist,par;

bool belman_ford(ll src){               //Returns false if their is negative sum cycle
    dist[src]=0;
    for(ll i=1;i<n;i++){
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
void printPath(ll des){                         // To print the shortest path from src to destination
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

int main(){
    return 0;
}