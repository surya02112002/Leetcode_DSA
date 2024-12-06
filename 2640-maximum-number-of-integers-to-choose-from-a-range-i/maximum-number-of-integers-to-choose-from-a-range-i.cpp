class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int count = 0;
        unordered_set<int> s(banned.begin(), banned.end());
        for(int i = 1; i<=n; i++){
            if(s.find(i) == s.end() && maxSum >= i){
                count++;
                maxSum -= i;
            }
        }
        return count;
    }
};