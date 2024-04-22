import sys
import math

N = int(input())

# sys.set_int_max_str_digits(20000)

x = 47683715819835662841796875
x *= 5 ** 50
ans = ''
cnt = 1
for _ in range(11):
    ans += str(x) * cnt
    cnt = math.ceil(cnt * 1.5)
    x //= 5 ** 5
print(ans)
