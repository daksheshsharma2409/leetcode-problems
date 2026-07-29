class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        using nestedPair = pair<int, pair<int, int>>;
        priority_queue<nestedPair, vector<nestedPair>, greater<nestedPair>> pq;

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        pq.push({0, {0,0}});
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        while (pq.size()){
            nestedPair it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if (row == n-1 && col == m-1) return diff;
            for (int i = 0; i<=3; i++){
                int newr = row + dr[i];
                int newc = col + dc[i];
                if (newr>=0 && newc>=0 && newr<n && newc<m){
                    int newEffort = max(abs(heights[row][col] - heights[newr][newc]), diff);
                    if (newEffort < dist[newr][newc]){
                        dist[newr][newc] = newEffort;
                        pq.push({newEffort, {newr, newc}});
                    }
                }
            }
        }
        return 0;
    }
};