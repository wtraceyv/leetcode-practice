class Solution:
    def isValid(self, s: str) -> bool:
        check_stack = []
        for c in s:
            if c in ['(', '[', '{']:
                check_stack.append(c)
            else:
                if len(check_stack) == 0:
                    return False
                top = check_stack[len(check_stack)-1]
                if (c == ')' and top == '(') or (c == ']' and top == '[') or (c == '}' and top == '{'):
                    check_stack.pop()
                else:
                    return False
        if len(check_stack) == 0:
            return True
        else:
            return False

# You can also use a map and it is much prettier, 
# but uses more memory. Everything's a trade off huh mate