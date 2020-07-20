from math import pi

A,N = (float(x) for x in input().split(' '))

r = N / pi

if A > N * N / (4 * pi):
    print('Need more materials!')
else:
    print('Diablo is happy!')
