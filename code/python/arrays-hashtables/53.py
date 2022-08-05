class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        allmax = nums[0]
        for i in range(1, len(nums)):
            local_max = max(nums[i], nums[i-1] + nums[i])
            nums[i] = local_max
            allmax = max(allmax, local_max)
        return allmax
