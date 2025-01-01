class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int zeroes=0;

        for(int i=0; i<n; i++){
            if(s[i] == '0'){
                zeroes++;
            }
        }

        int newZero=0, one=0, ans=0;
        for(int i=n-1; i>=0; i--){
            if(s[i] == '1') one++;
            else newZero++;

            ans = max(ans, one - (i == 0) + (zeroes-newZero));
        }
        return ans;
    }
};