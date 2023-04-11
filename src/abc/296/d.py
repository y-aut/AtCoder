# 入力
n, m = map(int, input().split())

# N以下の整数の中で、M以上の最小の数を求める
x = -1
for i in range(1, n+1):
    if m % i == 0 and m // i <= n:
        x = m
        break

# 結果を出力
print(x)
