class Solution:
    def isPalindrome(self, x: int) -> bool:
        y=0
        a=x
        while x>0:
            z=x%10
            y=y*10+z
            x=x//10
      
        return y==a

