def integerReplacement(self, n: int) -> int:        
        current = set([n])
        steps = 0
        while True:
            if 1 in current:
                return steps
            else:
                steps += 1
                new_current = set([])
                for num in current:
                    if num%2 == 1:
                        a = num+1
                        b = num-1
                        new_current.add(a)
                        new_current.add(b)
                    else:
                        new_current.add(int(num/2))
                current = new_current
