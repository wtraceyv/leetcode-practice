class Solution:
    def search(self, nums: List[int], target: int) -> int:
        low = 0
        high = len(nums) - 1
        mid = -1
        while low <= high:
            mid = math.floor((high - low) / 2) + low
            if nums[mid] == target:
                return mid
            if target > nums[mid]:
                low = mid + 1
            else:
                high = mid - 1
        return -1
