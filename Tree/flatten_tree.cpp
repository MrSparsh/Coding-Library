
vl tree;
ll st[400001],ed[400001],sec=0;

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
