class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        s_memo = defaultdict(lambda:0)
        t_memo = defaultdict(lambda:0)
        # No way base case
        if len(s) != len(t):
          return False
        # fill memos, O(2n)
        for c in s:
          s_memo[c] += 1
        for c in t:
          t_memo[c] += 1
        # check memos matching, O(n)
        for c in s_memo:
          if s_memo[c] != t_memo[c]:
            return False
        
        return True