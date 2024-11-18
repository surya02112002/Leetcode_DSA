class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        int mini= prices[0];
        int maxi= INT_MIN;
        if(n==1) return 0;
        for(int i=1; i<n;i++){
            int profit=prices[i]- mini;
            mini= min(mini,prices[i]);
            maxi= max(0,max(maxi, profit));
        }
        return maxi;
    }
};