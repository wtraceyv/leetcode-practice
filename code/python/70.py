# easy dynamic programming memoized way
class Solution:
    memo = {}

    def climbStairs(self, n: int) -> int:
        if n == 1:
            return 1
        if n == 2:
            return 2
        if n in self.memo:
            return self.memo[n]
        else:
            self.memo[n] = self.climbStairs(n - 2) + self.climbStairs(n - 1)
            return self.memo[n]
