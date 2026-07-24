class Solution {
private:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& vis, vector<int>& pathVis){
        vis[node] = 1;
        pathVis[node] = 1;
        for (auto i : graph[node]){
            if (vis[i]){
                if (pathVis[i]) return true;
            }
            else{
                if (dfs(i, graph, vis, pathVis)) return true;
            }
        }
        pathVis[node] = 0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        for (auto it : prerequisites){
            graph[it[1]].push_back(it[0]);
        }
        for (int i = 0; i<numCourses; i++){
            if (!vis[i]){
                if (dfs(i, graph, vis, pathVis)) return false;
            }
        }
        return true;
    }
};