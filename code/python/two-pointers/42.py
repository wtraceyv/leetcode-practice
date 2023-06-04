# definitely needed help understanding methodology,
# this one also happens to be constant space; 
# there is also a common solution that uses a few arrays
# to save maxL / maxR at each position and do minimums with that.
class Solution:
    def trap(self, height: List[int]) -> int:
        if not height:
            return 0

        end = 0
        l, r = 0, len(height) - 1
        maxL, maxR = height[l], height[r]
        while l < r:
            if maxL < maxR:
                l += 1
                maxL = max(maxL, height[l])
                end += maxL - height[l]
            else:
                r -= 1
                maxR = max(maxR, height[r])
                end += maxR - height[r]
        return end
