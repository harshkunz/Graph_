// solution using khan's algo

string findOrder(string dict[], int n, int k) {
    vector<vector<int>> adj(k);

    for (int i = 0; i < n - 1; i++) {
        string a = dict[i];
        string b = dict[i + 1];
        
        for (int j = 0; j < min(a.size(), b.size()); j++) {
            if (a[j] != b[j]) {
                adj[a[j] - 'a'].push_back(b[j] - 'a');
                break;
            }
        }
    }
    
    vector<int> in_deg(k, 0);
    for (int i = 0; i < k; i++) {
        for (auto it : adj[i]) {
            in_deg[it]++;
        }
    }
    
    queue<int> q;
    for (int i = 0; i < k; i++) {
        if (in_deg[i] == 0) {
            q.push(i);
        }
    }
    
    // Perform Kahn's Algorithm for topological sorting
    vector<char> ans;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(static_cast<char>(node + 'a')); // Correctly cast to char
        
        for (auto it : adj[node]) {
            in_deg[it]--; 
            if (in_deg[it] == 0) {
                q.push(it);
            }
        }
    }
    
    // Convert vector<char> to string
    return string(ans.begin(), ans.end());
}

// some modification

string findOrder(string dict[], int n, int k) {
    vector<vector<int>> adj(k);
    vector<int> in_degree(k, 0);

    for (int i = 0; i < n - 1; i++) {
        string word1 = dict[i];
        string word2 = dict[i + 1];
        
        for (int j = 0; j < min(word1.size(), word2.size()); j++) {
            if (word1[j] != word2[j]) {
                adj[word1[j] - 'a'].push_back(word2[j] - 'a');   // convert char to int
                in_degree[word2[j] - 'a']++;   // increment in-degree 
                break;
            }
        }
    }

    queue<int> q;
    for (int i = 0; i < k; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    string order;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        order += static_cast<char>(node + 'a');    // convert int to char

        for (int neighbor : adj[node]) {
            in_degree[neighbor]--;
            if (in_degree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // If order size is less than k, there was a cycle
    return order.size() == k ? order : "";
}

