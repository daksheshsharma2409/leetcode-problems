class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& result) {
        if (node == graph.size() - 1) {
            result.push_back(path);
            return;
        }

        for (int neighbor : graph[node]) {
            path.push_back(neighbor);
            dfs(neighbor, graph, path, result);
            path.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> path = {0};
        dfs(0, graph, path, result);
        return result;
    }
};