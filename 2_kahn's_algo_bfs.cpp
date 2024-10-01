// kahn's algo_bfs

vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> in_deg(V, 0);
	    for(int i=0; i<V; i++){
	        for(auto it : adj[i]){
	            in_deg[it]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i=0; i<V; i++){
	        if(in_deg[i] == 0){
	            q.push(i);
	        }
	    }
	    
	    vector<int> topo;
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        
	        topo.push_back(node);
	        for(auto it : adj[node]){
	            in_deg[it]--;
	            if(in_deg[it] == 0){
	                q.push(it);
	            }
	        }
	    }
	    
	    return topo;
	}