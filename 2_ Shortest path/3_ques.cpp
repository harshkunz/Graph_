// Cheapest Flights Within K Stops

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int, int>>> adj(n);   // create graph -> edges
        for(auto it : flights){
            adj[it[0]].push_back({it[1], it[2]});
        }

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}}); // {stop, {node, price}}

        vector<int> prices(n, 1e9);
        prices[src] = 0;

        while(!q.empty()){
            int u = q.front().second.first;
            int stop = q.front().first;
            int price = q.front().second.second;
            q.pop();

            if(stop > k){
                continue;
            }

            for(auto it: adj[u]){
                int v = it.first;
                int wt = it.second;

                if(price + wt < prices[v]){
                    prices[v] = price + wt;
                    q.push({stop + 1, {v, prices[v]}});
                }

            }
        }
        if(prices[dst] == 1e9){
            return -1;
        }
        return prices[dst];
    }