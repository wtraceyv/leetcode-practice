# pretty much understood the prefix and postfix array strategy, 
# but obviously in-place is better at least by memory standards
# One run to instill prefix values, then run back the other way for postfix
# Also note, don't need dummy values if just track pre and post fixes with an int and update it

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        end = [1] * len(nums)
        
        prefix = 1
        for i in range(len(nums)):
          end[i] = prefix
          prefix *= nums[i]
        postfix = 1
        for i in range(len(nums)-1, -1, -1):
          end[i] *= postfix
          postfix *= nums[i]
        return end