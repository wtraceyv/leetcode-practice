# Started out accidentally ignoring the memory constraint which forces it to be two pointers
# Just scan inward until you get a good answer and return those indices
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        lower, upper = 0, len(numbers) - 1
        current_sum = numbers[lower] + numbers[upper]
        while current_sum != target:
          if current_sum < target:
            lower += 1
          else:
            upper -= 1
          current_sum = numbers[lower] + numbers[upper]
        return [lower + 1, upper + 1]