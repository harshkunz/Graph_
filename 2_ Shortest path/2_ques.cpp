// Shortest Path in Binary Matrix

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(grid[0][0] != 0 || grid[m-1][n-1] != 0){
            return -1;
        }

        vector<pair<int, int>> directions = 
        {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

        // {distance, {i, j}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>> pq;

        pq.push({1, {0, 0}});
        vector<vector<int>> dis(m, vector<int>(n, 1e9));
        dis[0][0] = 1; 

        while(!pq.empty()){
            int wt = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();

            if(i == m-1 && j == n-1){
                return wt;
            }

            for(auto it : directions){
                int di = i + it.first;
                int dj = j + it.second;

                if(di>=0 && di<m && dj>=0 && dj<n && grid[di][dj] == 0){
                    if(wt + 1 < dis[di][dj]){
                        dis[di][dj] = wt + 1;
                        pq.push({dis[di][dj], {di, dj}});
                    }
                }
            }
        }
        return -1;
    }

// Path With Minimum Effort

int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, 
        greater<pair<int, pair<int, int>>>> pq;

        vector<vector<int>> effort(m, vector<int>(n, INT_MAX));
        pq.push({0, {0, 0}});
        effort[0][0] = 0;

        while (!pq.empty()) {
            auto [curEffort, pos] = pq.top();
            int i = pos.first, j = pos.second;
            pq.pop();

            if (i == m - 1 && j == n - 1) {
                return curEffort;
            }

            for (auto [di, dj] : dir) {
                int ni = i + di, nj = j + dj;
                if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                    int newEffort = max(curEffort, abs(heights[ni][nj] - heights[i][j]));
                    if (newEffort < effort[ni][nj]) {
                        effort[ni][nj] = newEffort;
                        pq.push({newEffort, {ni, nj}});
                    }
                }
            }
        }
        return 0;
    }