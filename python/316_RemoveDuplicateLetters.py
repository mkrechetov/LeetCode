def removeDuplicateLetters(self, s: str) -> str:
        last = {}
        for i, letter in enumerate(s):
            if letter not in last.keys():
                last[letter] = i
            else:
                last[letter] = i

        stackset = set([])
        stack = ""

        for i, letter in enumerate(s):
            if letter not in stackset:
                while stack:
                    if (stack[-1] > letter) and (last[stack[-1]] > i):
                        stackset.remove(stack[-1])
                        stack = stack[:-1]
                    else:
                        break
                stack += letter
                stackset.add(letter)
        return stack
