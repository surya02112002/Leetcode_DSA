class Solution {
public:
    bool checkPowersOfThree(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        while(n){
            int q = n / 3;
            int r = n - q * 3;
            if(q == 2 or r == 2) return false;
            n = q;
        }
        return true;
    }
};