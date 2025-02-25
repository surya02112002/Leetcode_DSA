class Solution {
public:
    int MOD = 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int result = 0;
        int prefixSum = 0, evenSumCnt = 1, oddSumCnt = 0;
        for(int i=0; i<n; i++){
            prefixSum += arr[i];
            if(prefixSum%2){
                result += evenSumCnt;
                oddSumCnt++;
            }
            else{
                result += oddSumCnt;
                evenSumCnt++;
            }
            result = result%MOD;
        }
        return result;
    }
};