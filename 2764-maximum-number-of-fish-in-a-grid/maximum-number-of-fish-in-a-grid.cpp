class Solution {
public:
    int fishesCaught;
    void DFS(vector<vector<int>>& grid, int row, int col) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 0)
            return;
        fishesCaught += grid[row][col];
        grid[row][col] = 0;
        DFS(grid, row + 1, col);
        DFS(grid, row - 1, col);
        DFS(grid, row, col + 1);
        DFS(grid, row, col - 1);
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int ans = 0;
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col] != 0) {
                    fishesCaught = 0;
                    DFS(grid, row, col);
                    ans = max(ans, fishesCaught);
                }
            }
        }
        return ans;
    }
};