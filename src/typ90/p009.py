import math
from bisect import bisect

N = int(input())
X = [list(map(int, input().split())) for _ in range(N)]

PI2 = 2 * math.pi


def get_arg2(t1, t2):
    dif = abs(t1 - t2)
    if dif > math.pi:
        return PI2 - dif
    return dif


max_ang = 0

for p in X:
    args = [math.atan2(q[1] - p[1], q[0] - p[0])
            for q in X if p[0] != q[0] or p[1] != q[1]]
    args.sort()
    indexes = [(arg, bisect(args, (arg + math.pi) % PI2) % (N - 1))
               for arg in args]
    args = [max(get_arg2(args[i - 1], arg), get_arg2(args[i], arg))
            for (arg, i) in indexes]
    max_ang = max(max_ang, *args)


print(math.degrees(max_ang))
