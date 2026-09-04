class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        s={}
        for i in range(len(nums)):
            a=target-nums[i]
            if a in s:
                return (s[a],i)
            s[nums[i]]=i