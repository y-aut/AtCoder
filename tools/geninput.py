import random as rd

T = 1
N = rd.randint(2, 10)
M = rd.randint(1, 10)
UV = []
for i in range(M):
    while True:
        u = rd.randint(1, N)
        v = rd.randint(1, N)
        if u != v:
            break
    UV.append((u, v))
UV = set(UV)
M = len(UV)

print(T)
print(N, M)
for p in UV:
    print(*p)
