import sys
import math
from bisect import bisect

sys.setrecursionlimit(10 ** 9)

N = int(input())
CP = [list(map(int, input().split())) for _ in range(N)]
Q = int(input())
LR = [list(map(int, input().split())) for _ in range(Q)]

bef = [0, 0]
tmp = [bef[:]]

for i in range(0, N):
    bef[CP[i][0] - 1] += CP[i][1]
    tmp.append(bef[:])


for l, r in LR:
    a = tmp[r][0] - tmp[l-1][0]
    b = tmp[r][1] - tmp[l-1][1]
    print(a, b)
