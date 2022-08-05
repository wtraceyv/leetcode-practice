# Did not run very 'fast' comparatively but I think the servers are just slammed
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums) == 0:
          return 0
        
        # setify so can constant-time check for consecutive nums
        checking = set(nums)
        longest = 1
        for n in nums:
          # if not the start of a sequence, skip
          if (n - 1) not in checking:
            # look for consecutive nums ahead
            cur_record = 1
            while (n + 1) in checking:
              n += 1
              cur_record += 1
              longest = max(longest, cur_record)
        
        return longest