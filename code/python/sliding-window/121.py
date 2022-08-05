class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        profit = 0
        min_buy = 10001  # can't be higher than this with constraint
        for p in range(0, len(prices)):
            min_buy = min(min_buy, prices[p])
            profit = max(profit, prices[p] - min_buy)
        return profit
