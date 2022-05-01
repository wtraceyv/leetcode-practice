class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        memo = defaultdict(lambda: 0)
        for i in range(0, len(nums)):
            if memo and (target - nums[i]) in memo:
                return [memo[target - nums[i]], i]
            else:
                memo[nums[i]] = i
