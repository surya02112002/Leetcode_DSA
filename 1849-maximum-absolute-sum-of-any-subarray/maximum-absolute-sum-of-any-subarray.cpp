class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int currMaxi = nums[0];
        int currMini = nums[0];
        int maxSum = nums[0];
        int minSum = nums[0];

        for(int i = 1 ;i<n;i++){
            currMaxi = max(nums[i],currMaxi+nums[i]);
            maxSum = max(maxSum,currMaxi);

            currMini = min(nums[i],currMini+nums[i]);
            minSum = min(minSum,currMini);
        }
        return abs(maxSum)>abs(minSum) ? abs(maxSum) : abs(minSum); 
    }
};