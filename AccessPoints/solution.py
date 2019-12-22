def dist1d(xs):
    i = 0
    res = 0
    while i < len(xs):
        j = i + 1
        while j < len(xs):
            sublist = xs[i:j+1]
            p = merge(sublist)
            if j+1 == len(xs):
                res += squared_cost(p, sublist)
                return res
            if xs[j+1] >= p:
                res += squared_cost(p, sublist)
                i = j
                break
            j += 1
        i += 1
    return res

def merge(xs):
    return sum(xs) / len(xs)

def squared_cost(p, xs):
    return sum([(p - x)**2 for x in xs])

l = [1,4]
p = merge(l)
print(p)
print(squared_cost(p, l))
print(dist1d(l))
