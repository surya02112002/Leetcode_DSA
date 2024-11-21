class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n= nums.size();
        int left= 0;
        int right=n-1;
        while(left<=right){
            int mid= (left+right)/2;
            if(target>nums[mid]){
                left=mid+1;
                // right=n-1;
            }
            else if(target<nums[mid]){
                // left=0;
                right=mid-1;
            }
            else if(nums[mid]==target){
                return mid;
            }
        }
        return -1;
    }
    
};