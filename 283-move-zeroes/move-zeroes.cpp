class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        
        int i = 0, j = 0;
        int n = nums.size();
        while(i < n and j < n)
        {
            if(nums[i] != 0) i++;
            if(nums[j] == 0) j++;

            if((i < n and j < n) and (i < j))
                swap(nums[i],nums[j]);
            
            j++;
        }
    }
};