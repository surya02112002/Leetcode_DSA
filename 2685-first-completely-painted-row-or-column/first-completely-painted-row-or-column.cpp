class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        vector<pair<int, int>> pos(m*n+1, {-1,-1});
        for(int i = 0 ; i < m; ++i)
        {
            for(int j = 0; j<n; ++j)
            {
                int num = mat[i][j];
                pos[num] = {i, j};
            }
        }

        vector<int> rows (m,0);
        vector<int> cols (n,0);


        for(int i = 0; i<arr.size(); ++i)
        {
            int num = arr[i];

            auto p = pos[num];

            int row =  p.first;
            int col = p.second;

            rows[row]++;
            cols[col]++;

            if( rows[row] ==n || cols[col]==m)
                return i;

        }

        return -1;
    }
};