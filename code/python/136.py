class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        result = nums[0]
        for n in range(1, len(nums)):
            result ^= nums[n]
        return result
