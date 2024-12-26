class Solution {
public:
    int expression (vector<int>&nums ,int s, int &target, int i, int currsum, vector<vector<int> > &dp)
    {
        if(i == nums.size())
        {
            return currsum == target ? 1 : 0;
        }
        if(dp[i][currsum + s] != INT_MIN)
        {
            return dp[i][currsum + s];
        }
        int add = expression( nums, s, target, i+1, currsum+nums[i], dp);
        int subtract = expression( nums, s, target, i+1, currsum-nums[i], dp);

        return dp[i][currsum+s] = add + subtract;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n  = nums.size();
        int s = accumulate( begin(nums), end(nums), 0 );
        vector<vector<int>> dp(n, vector<int>(2*s+1, INT_MIN));
        return expression(nums, s, target, 0, 0, dp);
    }
};