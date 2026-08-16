class Solution {
private:
    long long memo[65536][16];
    int pow2[16];
    
    long long dfs(int visited, int curr, int start, const vector<vector<int>>& requests){
        if (visited == pow2[curr]){
            long long arrival = requests[curr][0];
            long long time = abs(start - requests[curr][1]);
            return max(arrival, time);
        }
        
        if (memo[visited][curr] != -1){
            return memo[visited][curr];
        }

        long long min_t = 1e18;

        int prev = visited - pow2[curr];

        for (int nreq = 0; nreq < requests.size(); nreq++){
            if ((prev / pow2[nreq]) % 2 == 1){
                long long tap = dfs(prev, nreq, start, requests);
                long long travel = abs(requests[nreq][1] - requests[curr][1]);
                long long arrival = requests[curr][0];

                long long finish = max(tap + travel, arrival);

                min_t = min(min_t, finish);
            }
        }

        return memo[visited][curr] = min_t;
    }
public:
    long long elevatorRequests(int n, int start, vector<vector<int>>& requests) {
        int m = requests.size();

        pow2[0] = 1;
        for (int i = 1; i<m; i++){
            pow2[i] = pow2[i-1] * 2;
        }

        for (int i = 0; i<65536; i++){
            for (int j = 0; j<16; j++){
                memo[i][j] = -1;
            }
        }

        long long res = 1e18;

        int curr = 0;
        for (int i = 0; i<m; i++){
            curr += pow2[i];
        }
        for (int i = 0; i<m; i++){
            res = min(res, dfs(curr, i, start, requests));
        }

        return res;
    }
};