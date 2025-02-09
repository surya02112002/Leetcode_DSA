class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> hash;
        long long n = nums.size();
        long long tPair = (n * (n - 1)) / 2;
        long long gPair = 0;
        
        for (int i = 0; i < n; i++) {
            int key = nums[i] - i;
            gPair += hash[key];  
            hash[key]++;  
        }
        
        return tPair - gPair;
    }
};