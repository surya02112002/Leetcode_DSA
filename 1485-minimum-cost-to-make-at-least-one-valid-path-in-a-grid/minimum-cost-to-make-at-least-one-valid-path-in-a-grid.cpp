class Solution {
public:
    int minCost(vector<vector<int>>& grid) {

        int n = grid.size();

        int m = grid[0].size();

        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;

        deque<pair<int, int>> dq;
        dq.push_back({0, 0});

        while (!dq.empty()) {
            auto current = dq.front();
            dq.pop_front();

            int row = current.first;
            int col = current.second;

            for (int i = 0; i < 4; i++) {
                int newr = row + dr[i];
                int newc = col + dc[i];

                if (newr >= 0 && newr < n && newc >= 0 && newc < m) {

                    int gridDir = grid[row][col] - 1;

                    int dirCost = (gridDir == i) ? 0 : 1;

                    int newCost = dist[row][col] + dirCost;

                    if (newCost < dist[newr][newc]) {
                        
                        dist[newr][newc] = newCost;

                        if (dirCost == 0) {
                            dq.push_front({newr, newc});
                        }
                        else {
                            dq.push_back({newr, newc});
                        }
                    }
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};