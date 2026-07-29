class Graph {
public:
    vector<vector<pair<int, int>>> adj;
    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for (vector<int>& edge : edges){
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> arr(adj.size(), 1e9);
        arr[node1] = 0;
        pq.push({0, node1});
        while (pq.size()){
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            if (node == node2) return dist;
            for (auto it : adj[node]){
                int v = it.first;
                int wt = it.second;

                if (dist + wt < arr[v]){
                    arr[v] = dist + wt;
                    pq.push({arr[v], v});
                }
            }
        }
        if (arr[node2] == 1e9) return -1;
        return arr[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */