class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double wt = succProb[i];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        priority_queue<pair<double, int>> maxHeap;
        vector<double> probability(n, 0);
        probability[start_node] = 1;
        maxHeap.push({1, start_node});

        while (maxHeap.size()){
            double prob = maxHeap.top().first;
            int node = maxHeap.top().second;
            maxHeap.pop();

            for (auto it : adj[node]){
                int v = it.first;
                double wt = it.second;
                
                if (prob * wt > probability[v]){
                    probability[v] = prob * wt;
                    maxHeap.push({probability[v], v});
                }
            }
        }
        return probability[end_node];
    }
};