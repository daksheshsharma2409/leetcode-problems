class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> inDeg(numCourses, 0);
        for (vector<int>& g : prerequisites){
            graph[g[1]].push_back(g[0]);
            inDeg[g[0]]++;
        }

        queue<int> q;
        vector<int> topo;
        
        for (int i=0; i<numCourses; i++){
            if (!inDeg[i]) q.push(i);
        }

        while (q.size()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (auto it : graph[node]){
                inDeg[it]--;
                if (!inDeg[it]) q.push(it);
            }
        }
        if (!(topo.size() == numCourses)) return {};
        return topo;
    }
};