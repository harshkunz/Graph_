// 399. Evaluate Division

void dfs(string src, string dst, unordered_map<string, vector<pair<string, double>>>& adj,
unordered_set<string>& vis, double product, double& ans){
    if(vis.find(src) != vis.end()){
        return;
    }
    vis.insert(src); // mark as visited
    if(src == dst){
        ans = product;
        return;
    }

    for(auto & it : adj[src]){
        string v = it.first;
        double wt = it.second;
        dfs(v, dst, adj, vis, product*wt, ans);
    }
}

vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

    int n = equations.size();
    unordered_map<string, vector<pair<string, double>>> adj;

    // build a graph
    for(int i=0; i<n; i++){
        string u = equations[i][0];
        string v = equations[i][1];
        double wt = values[i];

        adj[u].push_back({v, wt});
        adj[v].push_back({u, 1.0/wt});
    }

    vector<double> res;

    for(auto &q : queries){
        string src = q[0];
        string dst = q[1];

        double ans = -1.0;
        double product = 1.0;

        if(adj.find(src) != adj.end()){
            unordered_set<string> vis;
            dfs(src, dst, adj, vis, product, ans);
        }

        res.push_back(ans);
    }

    return res;
}