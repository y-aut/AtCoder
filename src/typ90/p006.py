import sys

sys.setrecursionlimit(10 ** 9)

N, K = map(int, input().split())
S = input()

# (N-i) 文字目以降の文字列で，文字 j が最初に登場するインデックス
bucket = []
before = [-1 for _ in range(26)]

for i in range(N-1, -1, -1):
    before[ord(S[i]) - ord('a')] = i
    bucket.append(before[:])

start = 0
length = K
while length != 0:
    for c in range(26):
        ind = bucket[N-1-start][c]
        if start <= ind and ind <= N - length:
            print(S[ind], end="")
            start = ind + 1
            break
    length -= 1
print()
