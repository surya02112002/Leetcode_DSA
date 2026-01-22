class Solution:
    def is_non_decreasing(self, arr):

        i = 0
        while(i < len(arr) - 1):
            
            if(arr[i + 1] < arr[i]):
                return False
            i += 1

        return True
    
    def get_min_sum_index(self, arr):

        min_index = None
        min_sum = int(2 ** 31 - 1)

        i = 0
        while(i < len(arr) - 1):
            
            temp_sum = arr[i] + arr[i + 1]
            if(temp_sum < min_sum):
                min_sum = temp_sum
                min_index = i            
            i += 1

        return min_index
    
    def minimumPairRemoval(self, nums: list[int]) -> int:

        if(len(nums) == 1):
            return 0

        ans = 0

        while(not self.is_non_decreasing(nums)):

            i = self.get_min_sum_index(nums)
            nums[i] = nums[i] + nums[i + 1]
            nums.pop(i + 1)
            ans += 1

        return ans
        