class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1),prev(n,-1);
        int maxi=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    prev[i]=j;
                }
            }
            if(dp[i]>dp[maxi]) maxi=i;
        }
        vector<int> res;
        for(int i=maxi;i>=0;i=prev[i]){
            res.push_back(nums[i]);
            if(prev[i]==-1) break;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};