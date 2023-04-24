N, T = map(int, input().split())
C = list(map(int, input().split()))
R = list(map(int, input().split()))

ans1 = 0
ans2 = 0
p1 = 0
p2 = 0

color2 = C[0]

for i in range(N):
    if C[i] == T:
        if R[i] > ans1:
            ans1 = R[i]
            p1 = i+1
    elif C[i] == color2:
        if R[i] > ans2:
            ans2 = R[i]
            p2 = i+1

if ans1 != 0:
    print(p1)
else:
    print(p2)
