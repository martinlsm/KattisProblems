from sys import stdin
from math import factorial

for line in stdin:
    line = line.strip('\n')
    d = {}
    for c in line:
        if not c in d:
            d[c] = 1
        else:
            d[c] += 1
    result = factorial(len(line))
    for n in d.values():
        result //= factorial(n)
    print(result)

