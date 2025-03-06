class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        map<int,int>m1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                m1[grid[i][j]]++;
            }
        }
        int repeat;
        int missing;
        for(int i=1;i<=n*m;i++){
            if(m1[i] == 0) missing = i;
            else if (m1[i] > 1) repeat = i;
        }
        return {repeat,missing};
    }
};