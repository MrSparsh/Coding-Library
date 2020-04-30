// Disjoint-Set Union

#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll p[100001];
ll init(ll n){
    for(int i=1;i<=n;i++) p[i]=i;
}
ll find(ll x){
    if(x!=p[x]) return p[x]=find(p[x]);
    else return x;
}
void Union(ll x,ll y){
    ll px=p[x];
    ll py=p[y];
    if(px!=py){
        p[px]=py;
    }
}
int main(){

    return 0;
}