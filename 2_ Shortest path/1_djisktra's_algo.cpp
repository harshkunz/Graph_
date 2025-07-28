vector <int> dijkstra(int N, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push({S, 0});
        vector<int> dis(N, 1e9);
        dis[S] = 0;
        
        while(!pq.empty()){
            int u = pq.top().first;
            int dist = pq.top().second;
            pq.pop();
            
            for(auto it : adj[u]){
                int v = it[0];
                int wt = it[1];
                if(dist + wt < dis[v]){
                    dis[v] = dist + wt;
                    pq.push({v, dis[v]});
                }
            }
        }
        
        for(int i=0; i<N; i++){
            if(dis[i] == 1e9){
                dis[i] = -1;
            }
        }
        return dis;
    }
