import random as rd

N = rd.randint(3, 10)

M = 0
UVW = []
for i in range(1, N+1):
    for j in range(i+1, N+1):
        if rd.randint(0, 2) == 0:
            M += 1
            UVW.append((i, j, rd.randint(1, 10)))

if M == 0:
    M = 1
    UVW.append((1, 2, rd.randint(1, 10)))

K = 0
A = []
for i in range(1, N+1):
    if rd.randint(0, 2) == 0:
        K += 1
        A.append(i)

if K == 0:
    K = 1
    A.append(1)

D = rd.randint(1, 10)
X = []
for i in range(D):
    X.append(rd.randint(1, 10))

print(N, M)
for p in UVW:
    print(*p)
print(K)
print(*A, sep='\n')
print(D)
print(*X, sep='\n')
