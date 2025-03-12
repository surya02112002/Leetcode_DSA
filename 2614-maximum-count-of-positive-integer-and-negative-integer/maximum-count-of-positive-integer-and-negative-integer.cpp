class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        if (nums[0] > 0)
            return n;
        else if (nums[0] == 0 && nums[n - 1] == 0)
            return 0;
        else if (nums[0] < 0 && nums[n - 1] < 0)
            return n;
        
        auto lastneg = lower_bound(nums.begin(), nums.end(), 0);
        auto firstpos = upper_bound(nums.begin(), nums.end(), 0);
        
        int negcnt = lastneg - nums.begin();   
        int poscnt = nums.end() - firstpos;    
        
        return max(poscnt, negcnt);
    }
};