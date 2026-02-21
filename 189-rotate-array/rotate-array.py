class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        l= len(nums)
        k=k%l
        def reverse(left, right):
            while left< right:
                nums[left], nums[right]= nums[right] , nums[left]
                left+=1
                right -=1
        reverse(0, l-1)
        reverse(0, k-1)
        reverse(k, l-1)