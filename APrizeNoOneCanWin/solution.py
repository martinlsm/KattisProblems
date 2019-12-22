line = input().split()
N = int(line[0])
X = int(line[1])

items = [int(x) for x in input().split()]
items.sort()
ans = next((i for i in range(1,N) if items[i-1] + items[i] > X), N)

print(ans)
