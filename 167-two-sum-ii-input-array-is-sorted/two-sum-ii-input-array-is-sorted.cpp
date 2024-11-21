class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n= numbers.size();
        int left=0;
        int right=n-1;
        while(left<right){
            int total = numbers[left]+numbers[right];
            if(total<target){
                left++;
            }
            else if(total>target){
                right--;
            }
            else{
                return {left+1, right+1};   
            }
        }
        return {-1,-1};
    }
};