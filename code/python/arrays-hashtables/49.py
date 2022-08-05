# First idea was naive, sort strings going through and reassemble them.
# Would've been ~n^2logn
# Instead you can count letters and key the dict by tuples of the char counts
# And also just append the original str straight to the end dict after that
# O(M*N) (look at every string and then all of each string's characters)

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        end = collections.defaultdict(list)
        
        for s in strs:
          letters = [0] * 26
          for c in s:
            letters[ord(c) - ord('a')] += 1
          end[tuple(letters)].append(s)
        return end.values()