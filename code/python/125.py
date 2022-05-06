class Solution:
    def isPalindrome(self, s: str) -> bool:
        # do some cleaning
        # https://datascienceparichay.com/article/python-remove-non-alphanumeric-characters-from-string/
        cleaned = ''.join(c for c in s if c.isalnum())
        final = cleaned.lower()
        front = 0
        back = len(final) - 1
        while front < back:
            if final[front] != final[back]:
                return False
            front += 1
            back -= 1
        return True
