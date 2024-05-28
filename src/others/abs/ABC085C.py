N, Y = map(int, input().split())
Y //= 1000

if (Y < N):
    print(-1, -1, -1)
    exit()

d = Y - N
n_min = (2 * d + 8) // 9
n_max = min(d // 4, (N + d) // 5)

if n_min <= n_max:
    n = n_min
    print(d - 4*n, -2*d + 9*n, N - (5*n - d))
else:
    print(-1, -1, -1)
