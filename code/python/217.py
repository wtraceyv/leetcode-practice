class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        memo = {}
        for e in nums:
            if e not in memo:
                memo[e] = 1
            else:
                return True
        return False
