import math

T = int(input())
L, X, Y = map(int, input().split())
Q = int(input())
E = [int(input()) for _ in range(Q)]

for e in E:
    z = (1 - math.cos(e / T * 2 * math.pi)) * (L/2)
    y = -math.sin(e / T * 2 * math.pi) * (L/2)
    theta = math.atan2(z, math.sqrt(X**2 + (y-Y) ** 2))
    print(math.degrees(theta))
