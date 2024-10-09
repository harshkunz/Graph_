
class DisjointSet {
    vector<int> rank, size, parent;
public:
    // constructor
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i=0; i<n+1; i++){
            parent[i] = i;
        }
    }

    int findPar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findPar(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);

        if(ulp_u == ulp_v) return;  // Union by rank

        if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v){
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);

        if(ulp_u == ulp_v) return;  // Union by size
        
        if(size[ulp_u] > size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }

    int getSize(int u){
        return size[u];
    }
};