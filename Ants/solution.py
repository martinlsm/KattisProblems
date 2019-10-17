N_cases = int(input())

for n in range(N_cases):
    length,N_ants = [int(x) for x in input().split()]
    ants = []
    while len(ants) < N_ants:
        ants = ants + [int(x) for x in input().split()]
    timetuples = [(x, length - x) for x in ants]

    earliest = max((min(x, length - x) for x in ants))
    latest = max((max(x, length - x) for x in ants))

    print('{} {}'.format(earliest, latest))
