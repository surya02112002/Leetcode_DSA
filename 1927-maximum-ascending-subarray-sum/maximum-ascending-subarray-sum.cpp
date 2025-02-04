class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = nums[0], maxSum = nums[0];
        for(int i = 1; i<nums.size(); i++){
            if(nums[i-1] < nums[i]){
                sum += nums[i];
            }
            else{
                maxSum = max(sum, maxSum);
                sum = nums[i];
            }
        }
        maxSum = max(sum, maxSum);
        return maxSum;
    }
};