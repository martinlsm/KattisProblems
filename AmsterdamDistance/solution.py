import sys
import math

M, N, R = sys.stdin.readline().split(' ')
M = int(M); N = int(N); R = float(R)
ax,ay , bx,by = list(map(int, sys.stdin.readline().split(' ')))

dist_rad = abs(ay - by) * R/N
dist_circ = math.pi * (R * min(by, ay)) / N * abs(ax - bx) / M
opt_dist = min(R/N * (ay + by), dist_rad + dist_circ)
print(opt_dist)
