# fantastic space-wise, but not fast at all relatively
# maybe people keep a queue of maxes or something?
# I think it's O(nk)
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        result = []
        freq = collections.defaultdict(int)
        for n in nums:
          freq[n] += 1
        for i in range(0, k):
          maxKey = max(freq, key=freq.get)
          result.append(maxKey)
          freq.pop(maxKey)
        return result

# Uses bucket sort to sort things kind of for free in O(n),
# Since we know the number of buckets we need to begin with.
class Solution2:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # enough frequency buckets so that it would be valid if there were just 1 unique value:
        buckets = [[] for i in range(0, len(nums)+1)] 
        freq = collections.defaultdict(int)
        for n in nums:
          freq[n] += 1
        # Throw nums with corresponding frequencies into their buckets for O(n) sorting essentially
        # (Possible because we know the max size of the bucket array)
        for num, count in freq.items():
          buckets[count].append(num)
        # Count back from the top of frequencies until we have all k nums
        end = []
        for i in range(len(buckets)-1, 0, -1):
          if len(buckets[i]) > 0 and k > 0:
            for n in buckets[i]:
              end.append(n)
              k -= 1
        return end