// 1254. Number of Closed Islands

int closedIsland(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    DisjointSet ds(m*n);
    vector<pair<int, int>> del = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == 0){
                int u = i*n + j;
                for(auto it : del){
                    int di = it.first + i;
                    int dj = it.second + j;
                    if(di>=0 && di<m && dj>=0 && dj<n && grid[di][dj] == 0){
                        int v = di*n + dj;
                        if(ds.findPar(u) != ds.findPar(v)){
                            ds.unionByRank(u, v);
                        }
                    }
                }
            }
        }
    }

    int islands = 0;
    set<int> set;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == 0){
                int node = i*n + j;
                if(ds.findPar(node) == node){
                    islands++;
                }
                if(i==0 || i==m-1 || j==0 || j==n-1){
                    set.insert(ds.findPar(node));
                }
            }
        }
    }

    return islands - set.size();
}