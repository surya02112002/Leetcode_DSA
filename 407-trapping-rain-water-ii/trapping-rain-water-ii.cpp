class Solution {
public:
    int count = 0;
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    bool checkw(int i, int j, int n, int m) {
        return (i == 0 || j == 0 || i == n - 1 || j == m - 1);
    }
    
    bool check(int i, int j, int n, int m) {
        return (i >= 0 && j >= 0 && i < n && j < m);
    }
    
    void solve(vector<vector<int>>& v, vector<vector<int>>& vis, int n, int m) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (checkw(i, j, n, m)) {
                    pq.push({v[i][j], i, j});
                    vis[i][j] = 1;
                }
            }
        }
        
        while (!pq.empty()) {
            auto cell = pq.top(); pq.pop();
            int h = cell[0], in = cell[1], jn = cell[2];
            
            for (auto d : dir) {
                int r = in + d[0];
                int c = jn + d[1];
                
                if (check(r, c, n, m) && !vis[r][c]) {
                    vis[r][c] = 1;
                    if (v[r][c] < h) {
                        count += h - v[r][c];
                    }
                    pq.push({max(v[r][c], h), r, c});
                }
            }
        }
    }
    
    int trapRainWater(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        solve(v, vis, n, m);
        return count;
    }
};