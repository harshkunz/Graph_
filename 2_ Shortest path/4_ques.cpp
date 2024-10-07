// 1976. Number of Ways to Arrive at Destination

class Solution {
    typedef long long ll;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> adj[n];
        for(auto it : roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        pq.push({0, 0});   // {distance, node}
        
        vector<ll> dis(n, 1e18);  // handle larger value
        dis[0] = 0;
        vector<int> ways(n, 0);
        ways[0] = 1;

        int mod = (int)(1e9 + 7);

        while(!pq.empty()){
            ll dist = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            for(auto it: adj[u]){
                int v = it.first;
                int wt = it.second;

                if(dist + wt < dis[v]){
                    dis[v] = dist + wt;
                    pq.push({dis[v], v});
                    ways[v] = ways[u];
                }
                else if(dist + wt == dis[v]){
                    ways[v] = (ways[u] + ways[v]) % mod;
                }
            }
        }
        return ways[n - 1] % mod;
    }
};

// Minimum Multiplications to reach End (gfg)

class Solution {
    using ll = long long;
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        pq.push({0, start}); // mini steps {steps, node}
        
        vector<int> dis(100000, 1e9);
        dis[start] = 0;
        
        int mod = (int)(1e5);
        
        while(!pq.empty()){
            ll steps = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            if(u == end){
                return steps;
            }
            
            for(int i=0; i<arr.size(); i++){
                int v = (u * arr[i])%mod;
                
                if(steps + 1 < dis[v]){
                    dis[v] = steps + 1;
                    pq.push({steps + 1, v});
                }
            }
        }
        return -1;
    }
};