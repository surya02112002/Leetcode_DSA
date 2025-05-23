class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long totalSum = 0;
        int parityFlag = 0;
        long long minDiff = 1 << 30;
        
        for (auto &value : nums) {
            long long xorValue = value ^ k;
            totalSum += max((long long)value, xorValue);
            if (value < xorValue) {
                parityFlag = 1 - parityFlag;
            }
            minDiff = min(minDiff, abs(value - xorValue));
        }
        return totalSum - parityFlag * minDiff;
    }
};