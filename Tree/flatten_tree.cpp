// Flatten a tree
#include <bits/stdc++.h>  
using namespace std;
typedef long long ll;

vector<ll> tree;						// It will store flattened tree
ll st[400001],ed[400001],sec=0;			// st stores starting time and ed stores end time for every node
vector<vector<ll> > G;
void flattenTree(ll u,ll p){
	tree.push_back(u);
	st[u]=sec++;
	for(ll v:G[u]){
		if(v!=p){
			flattenTree(v,u);
		}
	}
	ed[u]=sec-1;
}
int main(){
	return 0;
}