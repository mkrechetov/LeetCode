def totalFruit(fruits):
    if len(fruits) <= 2: return len(fruits)
    else:
        lptr = 0
        rptr = 1
        basket = dict()
        basket[fruits[0]] = 0
        basket[fruits[1]] = 0
        basket[fruits[0]] += 1
        basket[fruits[1]] += 1
        best = 2

        while True:
            print("Begin:", [fruits[i] for i in range(lptr, rptr+1)])
            while True:
                rptr += 1
                if rptr == len(fruits):
                    if rptr-lptr > best:
                        best = rptr-lptr
                    return best
                elif fruits[rptr] not in basket.keys():
                    basket[fruits[rptr]] = 1
                    if len(basket.keys()) > 2:
                        if rptr-lptr > best:
                            best = rptr-lptr
                        break
                else:
                    basket[fruits[rptr]] += 1

            print("Middle:", [fruits[i] for i in range(lptr, rptr+1)])
            while len(basket) > 2:
                basket[fruits[lptr]] -= 1
                if basket[fruits[lptr]] == 0: del basket[fruits[lptr]]
                lptr += 1
            print("End:", [fruits[i] for i in range(lptr, rptr+1)])

        return best

assert totalFruit([1,2,1]) == 3
assert totalFruit([0,1,2,2]) == 3
assert totalFruit([1,2,3,2,2]) == 4

x = totalFruit([3,3,3,1,2,1,1,2,3,3,4])
print(x)
