import sys
import math

M, N, R = sys.stdin.readline().split(' ')
M = int(M); N = int(N); R = float(R)
ax,ay , bx,by = list(map(int, sys.stdin.readline().split(' ')))

# find the distance along the axis parallel to the radius
dist_rad = abs(ay - by) * R/N
# find the circular distance along min(ay, by)
dist_circ = math.pi * (R * min(by, ay)) / N * abs(ax - bx) / M
# compare with the solution of only going along the radius
opt_dist = min(R/N * (ay + by), dist_rad + dist_circ)
print(opt_dist)
