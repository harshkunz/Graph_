// 802. Find Eventual Safe States

void dfs(int node, vector<vector<int>>& graph, vector<int>& vis, vector<int>& vis_path, 
     vector<int>& safe) {
        vis[node] = 1;
        vis_path[node] = 1;  

        for (auto it : graph[node]) {
            if (!vis[it]) {
                dfs(it, graph, vis, vis_path, safe);
            }
            if (vis_path[it] == 1 || safe[it] == 0) {
                safe[node] = 0;
            }
        }

        vis_path[node] = 0; 
        if (safe[node] != 0) {
            safe[node] = 1;
        }
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int m = graph.size();
        vector<int> vis(m, 0);
        vector<int> vis_path(m, 0);
        vector<int> safe(m, -1);  // -1 means unvisited, 0 means unsafe, 1 means safe

        for (int i = 0; i < m; i++) {
            if (!vis[i]) {
                dfs(i, graph, vis, vis_path, safe);
            }
        }

        vector<int> ans;
        for (int i = 0; i < m; i++) {
            if (safe[i] == 1) { 
                ans.push_back(i);
            }
        }
        return ans;
    }