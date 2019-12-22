import itertools

def max_friends(tuple_list):
    tuple_list.sort(key=lambda x: 2*x[0] - x[1])
    l = [x[1] for x in tuple_list]
    l = itertools.accumulate(l, lambda x,y: x + y)
    return max(l)

n,k = (int(x) for x in input().split(" "))
l = []

for _ in range(n):
    en,ex = (int(x) for x in input().split(" "))
    l.append((en - k, 1))
    l.append((ex, -1))

print(max_friends(l))
