import sys

sys.setrecursionlimit(10 ** 9)

N = int(input())
S = input()

# 前の (i+1) 文字で atcoder の前から (j+1) 文字を何通り作れるか
before = [0 for _ in range(7)]

for i in range(N):
    tmp = [0 for _ in range(7)]
    for j in range(7):
        if i < j:
            break
        if S[i] == 'atcoder'[j]:
            tmp[j] = before[j] + (1 if j == 0 else before[j-1])
        else:
            tmp[j] = before[j]
    before = tmp

print(before[-1] % (10 ** 9 + 7))
