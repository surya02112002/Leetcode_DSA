class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<pair<int,vector<int>>> pr; 
        for(int i=0; i<rows; i++){
            for(int j=0; j< cols; j++){
                int d = abs(rCenter-i) + abs(cCenter - j);
                vector<int>temp;
                temp.push_back(i);
                temp.push_back(j);
                pr.push_back(make_pair(d,temp));
            }
        }
        
        sort(pr.begin(), pr.end());
        vector<vector<int>> ans;
        
        for(int i=0; i<pr.size(); i++){
            ans.push_back(pr[i].second);
        }
        return ans;
    }
};