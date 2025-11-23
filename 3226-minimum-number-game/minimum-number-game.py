class Solution:
    def numberGame(self, nums: List[int]) -> List[int]:
        nums.sort()
        arr=[]

        for i in range(0, len(nums),2):
            a= nums[i]
            b= nums[i+1]
            arr.append(b)
            arr.append(a)

        return arr