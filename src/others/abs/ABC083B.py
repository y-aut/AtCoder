N, A, B = map(int, input().split())

ans = 0
for i in range(1, N+1):
    s = str(i)
    tmp = 0
    for c in s:
        tmp += int(c)
    if A <= tmp and tmp <= B:
        ans += i

print(ans)
