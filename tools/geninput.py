import random as rd

N = rd.randint(1, 100)
A = []
B = []
for i in range(N):
    A.append(rd.randint(1, 10000))
    B.append(rd.randint(1, 10000))

print(N)
print(*A)
print(*B)
