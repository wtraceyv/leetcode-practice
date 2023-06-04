# Took tip on which side to go inward on,
# but mostly got here myself
class Solution:
    def maxArea(self, height: List[int]) -> int:
        curMax = 0
        l, r = 0, len(height) - 1

        while l < r:
            curArea = min(height[l], height[r]) * (r - l)
            curMax = max(curMax, curArea)
            # Move inward, aim to fix the current higher of the two options
            if height[l] <= height[r]:
                l += 1
            else:
                r -= 1

        return curMax
