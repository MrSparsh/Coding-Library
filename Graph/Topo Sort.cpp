    #include <bits/stdc++.h>
    using namespace std;
     
    #define SIZE 100000
     
    vector<int> graph[SIZE];
     
    int visited[SIZE] = {0};
    stack<int> topoOrder;
    void toposort(int node) {
    	visited[node] = 1;
    	for(int adj: graph[node]) {
    		if(!visited[adj]) {
    			toposort(adj);
    		}
    	}
    	topoOrder.push(node);
    }
     
    int main() {
    	int n, m;
    	int indegree[SIZE] = {0};
    	// here n is no of nodes and m is no of edges
    	cin>>n>>m;
     
    	// taking directed edges as input
    	for(int i=0;i<m;i++) {
    		int u, v;
    		cin>>u>>v;
    		graph[u].push_back(v);
    		indegree[v]++;
    	}
     
    	// toposort using dfs
    	printf("Using dfs, Topological Sort: \n");
    	for(int i=1;i<=n;i++) {
    		// we need to call dfs for all disconnected components if present
    		if(!visited[i]) {
    			toposort(i);
    		}
    	}
    	while(!topoOrder.empty()) {
    		printf("%d ", topoOrder.top());
    		topoOrder.pop();
    	}
    	printf("\n");
     
    	// toposort using indegree approach
    	printf("Using in-degree method, Topological Sort: \n");
    	queue<int> q;
    	vector<int> topoOrder2;
    	for(int i=1;i<=n;i++) {
    		if(indegree[i] == 0) {
    			q.push(i);
    		}
    	}
     
    	while(!q.empty()) {
    		int curr = q.front();
    		topoOrder2.push_back(curr);
    		q.pop();
     
    		for(int adj: graph[curr]) {
    			indegree[adj]--;
    			if(indegree[adj] == 0) {
    				q.push(adj);
    			}
    		}
    	}
    	for(int node: topoOrder2) {
    		printf("%d ", node);
    	}
    	printf("\n");
     
     
    	return 0;
    }