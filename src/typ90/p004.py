import sys

sys.setrecursionlimit(10 ** 9)

H, W = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(H)]

rowSum = [0 for _ in range(H)]
colSum = [0 for _ in range(W)]

for i in range(H):
    for j in range(W):
        rowSum[i] += A[i][j]
        colSum[j] += A[i][j]

for i in range(0, H):
    print(
        ' '.join(map(str, [rowSum[i] + colSum[j] - A[i][j] for j in range(W)])))
