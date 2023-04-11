A = int(input())
B = int(input())
C = int(input())
X = int(input())

cnt = 0

a = min(A, X // 500)
for i in range(a+1):
    x = X - 500 * i
    b = min(B, x // 100)
    b_cnt = b - max(0, ((x - C * 50) + 99) // 100) + 1
    if b_cnt <= 0:
        continue
    cnt += b_cnt

print(cnt)
