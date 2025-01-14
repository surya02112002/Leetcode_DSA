class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for(int i = 0; i<A.size(); i++){
            mp[A[i]]++;
            mp[B[i]]++;
            int count = 0;
            for(auto& m:mp){
                if(m.second == 2){
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};