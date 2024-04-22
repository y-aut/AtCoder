import sys
import math


def f(x):
    v = 0
    while x != 0:
        v += x % 10
        x //= 10
    return v


# x = 222044604922810862035476020537316799163818359375
# prev = f(x)
# for _ in range(102):
#     x *= 2
#     cur = f(x)
#     print(cur-prev)
#     prev = cur

# x = 9
# for i in range(100):
#     v = f(x)
#     tmp = x
#     while True:
#         tmp *= 5
#         cur = f(tmp)
#         if cur < v:
#             break
#         if cur > v:
#             prev = cur
#             cnt = 1
#             while True:
#                 tmp *= 5
#                 cur = f(tmp)
#                 if cur > prev:
#                     cnt += 1
#                     prev = cur
#                     continue
#                 else:
#                     break
#             print(f'i={i}, cnt={cnt}')
#             break
#     x *= 10
#     x += 9

sys.set_int_max_str_digits(20000)

x = 47683715819835662841796875
x *= 5 ** 50
ans = ''
cnt = 1
for _ in range(11):
    ans += str(x) * cnt
    cnt = math.ceil(cnt * 1.5)
    x //= 5 ** 5
print(len(ans))
print(ans)

# v = int(ans)
# prev = f(v)
# for i in range(50):
#     v *= 2
#     cur = f(v)
#     print(cur - prev)
#     prev = cur
